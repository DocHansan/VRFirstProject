// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseVRPawn.h"

// Sets default values
ABaseVRPawn::ABaseVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;

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
	AfterPressingTheButton = true;
}

// Called every frame
void ABaseVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

