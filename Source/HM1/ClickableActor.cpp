// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickableActor.h"

AClickableActor::AClickableActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void AClickableActor::Click_Implementation()
{
    StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), FVector(0.9f, 0.9f, 0.0f));
}