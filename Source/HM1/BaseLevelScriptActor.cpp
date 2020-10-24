// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLevelScriptActor.h"

void ABaseLevelScriptActor::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->SpawnActor<ASphereClickableActor>(ASphereClickableActor::StaticClass(), FVector(0.f, 0.f, 500.f), FRotator(0.f, 0.f, 0.f), FActorSpawnParameters());
    
    for (int i = -500; i <= 500; i += 100)
    {
        for (int j = 50; j <= 1050; j += 100)
        {
            GetWorld()->SpawnActor<ACubeClickableActor>(ACubeClickableActor::StaticClass(), FVector(-1000.f, i, j), FRotator(0.f, 0.f, 0.f), FActorSpawnParameters());
        }
    }
}