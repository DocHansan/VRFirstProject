// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLevelScriptActor.h"

void ABaseLevelScriptActor::BeginPlay()
{
    Super::BeginPlay();

    for (int i = -500; i < 600; i += 105)
    {
        for (int j = 50; j < 1150; j += 100)
        {
            GetWorld()->SpawnActor<ACubeClickableActor>(ACubeClickableActor::StaticClass(), FVector(-1000.f, i, j), FRotator(0.f, 0.f, 0.f), FActorSpawnParameters());
        }
    }

    for (int i = -500; i < 600; i += 105)
    {
        for (int j = 50; j < 1150; j += 100)
        {
            GetWorld()->SpawnActor<ACubePickableActor>(ACubePickableActor::StaticClass(), FVector(-3000.f, i, j), FRotator(0.f, 0.f, 0.f), FActorSpawnParameters());
        }
    }
}