// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLevelScriptActor.h"

void ABaseLevelScriptActor::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->SpawnActor<AInteractiveActor>(AInteractiveActor::StaticClass(), FVector(-100.0f, -170.0f, 90.0f), FRotator(0.0f, 0.0f, 0.0f), FActorSpawnParameters());
    
}