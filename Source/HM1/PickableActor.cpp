// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableActor.h"

APickableActor::APickableActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void APickableActor::Click_Implementation()
{
    StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), ChangeColor());

}

void APickableActor::BeginPlay()
{
    Super::BeginPlay();

}

void APickableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}