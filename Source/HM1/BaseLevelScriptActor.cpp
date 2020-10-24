// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLevelScriptActor.h"

void ABaseLevelScriptActor::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->SpawnActor<ASphereClickableActor>(ASphereClickableActor::StaticClass(), FVector(0.f, 0.f, 1000.f), FRotator(0.f, 0.f, 0.f), FActorSpawnParameters());
    
}