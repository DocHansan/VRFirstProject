// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickableActor.h"

void AClickableActor::Click_Implementation()
{
    StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), FVector(0.9f, 0.9f, 0.0f));
}