// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC_1.h"

// Sets default values
ABaseNPC_1::ABaseNPC_1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseNPC_1::BeginPlay()
{
	Super::BeginPlay();

	// FindAllActors(GetWorld(), TargetPoints);
	
}

// Called every frame
void ABaseNPC_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseNPC_1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/*
template<typename T>
void FindAllActors(UWorld* World, TArray<T*>& Out)
{
    for (TActorIterator<T> It(World); It; ++It)
    {
        Out.Add(*It);
    }
}
*/