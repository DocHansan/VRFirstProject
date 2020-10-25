// Fill out your copyright notice in the Description page of Project Settings.


#include "CubePickableActor.h"

ACubePickableActor::ACubePickableActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Накидываем меш сферы
    static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    StaticMeshComponent->SetStaticMesh(SphereMesh.Object);

    // Накидываем статический материал
    static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant>Material(TEXT("/Game/Materials/ColorInst.ColorInst"));
    ConstantMaterialInst = Material.Object;
    StaticMeshComponent->SetMaterial(0, ConstantMaterialInst);
}

void ACubePickableActor::BeginPlay()
{
    Super::BeginPlay();

    // Накидываем динамический материал
    DynamicMaterialInst = UMaterialInstanceDynamic::Create(ConstantMaterialInst, StaticMeshComponent);
    StaticMeshComponent->SetMaterial(0, DynamicMaterialInst);

}

void ACubePickableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}