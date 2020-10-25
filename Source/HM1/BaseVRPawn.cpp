// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseVRPawn.h"

// Sets default values
ABaseVRPawn::ABaseVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	ControllerLeft = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("ControllerLeft"));
	ControllerLeft->SetTrackingSource(EControllerHand::Left);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>ControllerMesh(TEXT("/Engine/VREditor/Devices/Vive/VivePreControllerMesh.VivePreControllerMesh")); 
	ControllerLeft->SetCustomDisplayMesh(ControllerMesh.Object);
	//ControllerLeft->MotionSource = FName(TEXT("Left"));
	ControllerLeft->AttachTo(RootComponent);

	ControllerRight = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("ControllerRight"));
	ControllerRight->SetCustomDisplayMesh(ControllerMesh.Object);
	ControllerRight->SetTrackingSource(EControllerHand::Right);
	//ControllerRight->MotionSource = FName(TEXT("Right"));
	ControllerRight->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ABaseVRPawn::BeginPlay()
{
	Super::BeginPlay();

	/*
	Определяем, будет ли прорисовка луча только после нажатия кнопки или же всегда
	False - отрисовывать всегда
	True - отрисовка только после нажатия на кнопку телепортации
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
