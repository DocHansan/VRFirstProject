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
	CollisionLeft->OnComponentBeginOverlap.AddDynamic(this, &ABaseVRPawn::OnOverlapBeginLeft);
	CollisionLeft->OnComponentEndOverlap.AddDynamic(this, &ABaseVRPawn::OnOverlapEndLeft);

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
	CollisionRight->OnComponentBeginOverlap.AddDynamic(this, &ABaseVRPawn::OnOverlapBeginRight);
	CollisionRight->OnComponentEndOverlap.AddDynamic(this, &ABaseVRPawn::OnOverlapEndRight);



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

	// Respond when our "PickUpLeft" key is pressed or released.
	InputComponent->BindAction("PickUpLeft", IE_Pressed, this, &ABaseVRPawn::PickUpLeft);
	InputComponent->BindAction("PickUpLeft", IE_Released, this, &ABaseVRPawn::DropLeft);

	// Respond when our "PickUpRight" key is pressed or released.
	InputComponent->BindAction("PickUpRight", IE_Pressed, this, &ABaseVRPawn::PickUpRight);
	InputComponent->BindAction("PickUpRight", IE_Released, this, &ABaseVRPawn::DropRight);
}

// Change color
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

// PickUp and Drop
void ABaseVRPawn::PickUpLeft()
{
	if (bIsOverlappingNowLeft && !bIsPickedUpNowLeft && OverlappingComponentLeft)
	{
		OverlappingComponentLeft->SetSimulatePhysics(true);
		OverlappingComponentLeft->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true));
		OverlappingComponentLeft->SetLinearDamping(100000);
		OverlappingComponentLeft->SetAngularDamping(100000);
		bIsPickedUpNowLeft = true;
	}
}

void ABaseVRPawn::DropLeft()
{
	if (bIsOverlappingNowLeft && bIsPickedUpNowLeft && OverlappingComponentLeft)
	{
		OverlappingComponentLeft->SetSimulatePhysics(false);
		OverlappingComponentLeft->SetLinearDamping(0.01f);
		OverlappingComponentLeft->SetAngularDamping(0.f);
		//GetWorldTimerManager().SetTimer(FTimerHandle(), this, &ABaseVRPawn::DetachFromComponentDelay(), 1.0f, true, 2.0f);
		OverlappingComponentLeft->DetachFromComponent(FDetachmentTransformRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, true));
		OverlappingComponentLeft->SetSimulatePhysics(true);
		bIsPickedUpNowLeft = false;
	}
}

void ABaseVRPawn::DetachFromComponentDelay(class UPrimitiveComponent* DetachingComp)
{
	DetachingComp->DetachFromComponent(FDetachmentTransformRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, true));
}

void ABaseVRPawn::PickUpRight()
{
	if (bIsOverlappingNowRight && !bIsPickedUpNowRight && OverlappingComponentRight)
	{
		OverlappingComponentRight->SetSimulatePhysics(true);
		OverlappingComponentRight->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true));
		OverlappingComponentRight->SetLinearDamping(100000);
		OverlappingComponentRight->SetAngularDamping(100000);
		bIsPickedUpNowLeft = true;
	}
}

void ABaseVRPawn::DropRight()
{
	if (bIsOverlappingNowRight && bIsPickedUpNowRight && OverlappingComponentRight)
	{
		OverlappingComponentRight->SetSimulatePhysics(false);
		OverlappingComponentRight->SetLinearDamping(0.01f);
		OverlappingComponentRight->SetAngularDamping(0.f);
		//GetWorldTimerManager().SetTimer(FTimerHandle(), this, &ABaseVRPawn::DetachFromComponentDelay(), 1.0f, true, 2.0f);
		OverlappingComponentRight->DetachFromComponent(FDetachmentTransformRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, true));
		OverlappingComponentRight->SetSimulatePhysics(true);
		bIsPickedUpNowRight = false;
	}
}

void ABaseVRPawn::OnOverlapBeginLeft(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && !bIsOverlappingNowLeft)
	{
		if (Cast<IPickableInterface>(OtherActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("start overlap left"));
			bIsOverlappingNowLeft = true;
			OverlappingComponentLeft = OtherComp;
		}
	}
}

void ABaseVRPawn::OnOverlapEndLeft(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp && (OtherComp == OverlappingComponentLeft))
	{
		UE_LOG(LogTemp, Warning, TEXT("end overlap left"));
		ABaseVRPawn::DropLeft();
		bIsOverlappingNowLeft = false;
		OverlappingComponentLeft = nullptr;
	}
}

void ABaseVRPawn::OnOverlapBeginRight(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && !bIsOverlappingNowRight)
	{
		if (Cast<IPickableInterface>(OtherActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("start overlap right"));
			bIsOverlappingNowRight = true;
			OverlappingComponentRight = OtherComp;
		}
	}
}

void ABaseVRPawn::OnOverlapEndRight(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp && (OtherComp == OverlappingComponentRight))
	{
		UE_LOG(LogTemp, Warning, TEXT("end overlap right"));
		ABaseVRPawn::DropRight();
		bIsOverlappingNowRight = false;
		OverlappingComponentRight = nullptr;
	}
}
