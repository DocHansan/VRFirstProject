// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseVRPawn.h"
#include "PickableInterface.h"

// Sets default values
ABaseVRPawn::ABaseVRPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// —оздание левого контроллера с мешем
	ControllerLeft = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("ControllerLeft"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>ControllerMesh(TEXT("/Engine/VREditor/Devices/Vive/VivePreControllerMesh.VivePreControllerMesh"));
	ControllerLeft->SetCustomDisplayMesh(ControllerMesh.Object);
	ControllerLeft->SetTrackingSource(EControllerHand::Left);
	//ControllerLeft->MotionSource = FName(TEXT("Left"));
	ControllerLeft->SetShowDeviceModel(true);
	ControllerLeft->SetDisplayModelSource(TEXT("Custom"));
	ControllerLeft->SetupAttachment(RootComponent);

	CollisionLeft = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionLeft"));
	CollisionLeft->InitCapsuleSize(6.f, 10.f);
	CollisionLeft->SetRelativeLocationAndRotation(FVector(10.f, 0.f, 0.f), FRotator(90.f, 0.f, 0.f));
	//CollisionLeft->SetGenerateOverlapEvents(true);
	CollisionLeft->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CollisionLeft->SetupAttachment(ControllerLeft);
	CollisionLeft->OnComponentBeginOverlap.AddDynamic(this, &ABaseVRPawn::OnOverlapBegin);
	CollisionLeft->OnComponentEndOverlap.AddDynamic(this, &ABaseVRPawn::OnOverlapEnd);

	// —оздание правого контроллера с мешем
	ControllerRight = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("ControllerRight"));
	ControllerRight->SetCustomDisplayMesh(ControllerMesh.Object);
	ControllerRight->SetTrackingSource(EControllerHand::Right);
	//ControllerRight->MotionSource = FName(TEXT("Right"));
	ControllerRight->SetShowDeviceModel(true);
	ControllerRight->SetDisplayModelSource(TEXT("Custom"));
	ControllerRight->SetupAttachment(RootComponent);

	CollisionRight = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionRight"));
	CollisionRight->InitCapsuleSize(6.f, 10.f);
	CollisionRight->SetRelativeLocationAndRotation(FVector(10.f, 0.f, 0.f), FRotator(90.f, 0.f, 0.f));
	CollisionRight->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CollisionRight->SetupAttachment(ControllerRight);



}

// Called when the game starts or when spawned
void ABaseVRPawn::BeginPlay()
{
	Super::BeginPlay();

	/*
	ќпредел€ем, будет ли прорисовка луча только после нажати€ кнопки или же всегда
	False - отрисовывать всегда
	True - отрисовка только после нажати€ на кнопку телепортации
	*/
	//bAfterPressingTheButton = true;
}

// Called every frame
void ABaseVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//// Called to bind functionality to input
//void ABaseVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

// Called to bind functionality to input
void ABaseVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// Respond when our "ChangeColorLeft" key is pressed or released.
	InputComponent->BindAction("ChangeColorLeft", IE_Pressed, this, &ABaseVRPawn::StartChangeColorLeft);
	InputComponent->BindAction("ChangeColorLeft", IE_Released, this, &ABaseVRPawn::StopChangeColorLeft);

	// Respond when our "ChangeColorRight" key is pressed or released.
	InputComponent->BindAction("ChangeColorRight", IE_Pressed, this, &ABaseVRPawn::StartChangeColorRight);
	InputComponent->BindAction("ChangeColorRight", IE_Released, this, &ABaseVRPawn::StopChangeColorRight);
}

void ABaseVRPawn::StartChangeColorLeft()
{
	bIsNeedChangeColorLeft = true;
}

void ABaseVRPawn::StopChangeColorLeft()
{
	bIsNeedChangeColorLeft = false;
}

void ABaseVRPawn::StartChangeColorRight()
{
	bIsNeedChangeColorRight = true;
}

void ABaseVRPawn::StopChangeColorRight()
{
	bIsNeedChangeColorRight = false;
}

void ABaseVRPawn::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && !bIsOverlapingNow)
	{
		UE_LOG(LogTemp, Warning, TEXT("overlap"));
		if (Cast<IPickableInterface>(OtherActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("cast"));
			OtherComp->SetSimulatePhysics(true);
			OtherComp->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true));
			OtherComp->SetLinearDamping(100000);
			OtherComp->SetAngularDamping(100000);
			bIsOverlapingNow = true;
			OverlapingComponent = OtherComp;
		}
	}
}

void ABaseVRPawn::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp && (OtherComp == OverlapingComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("end overlap"));
		OtherComp->DetachFromComponent(FDetachmentTransformRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, true));
		OtherComp->SetLinearDamping(0.01f);
		OtherComp->SetAngularDamping(0.f);
		bIsOverlapingNow = false;
		OverlapingComponent = nullptr;
	}
}
