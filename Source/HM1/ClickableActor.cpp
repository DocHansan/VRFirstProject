// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickableActor.h"

AClickableActor::AClickableActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void AClickableActor::Click_Implementation()
{
    StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), ChangeColor());

}

void AClickableActor::BeginPlay()
{
    Super::BeginPlay();

}

void AClickableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}