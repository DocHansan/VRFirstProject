// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeClickableActor.h"

ACubeClickableActor::ACubeClickableActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Накидываем меш сферы
    static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("/Game/Meshes/CubeMesh_2.CubeMesh_2"));
    StaticMeshComponent->SetStaticMesh(SphereMesh.Object);

    // Накидываем статический материал
    static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant>Material(TEXT("/Game/Materials/ColorInst.ColorInst"));
    ConstantMaterialInst = Material.Object;
    StaticMeshComponent->SetMaterial(0, ConstantMaterialInst);

    static ConstructorHelpers::FObjectFinder<UPhysicalMaterial>PhysMaterial(TEXT("/Game/Materials/SpherePhysicalMaterial.SpherePhysicalMaterial"));
    PhysicalMaterial = PhysMaterial.Object;
    StaticMeshComponent->SetPhysMaterialOverride(PhysicalMaterial);

    // Change mass
    StaticMeshComponent->SetMassOverrideInKg(NAME_None, 15.f);
}

void ACubeClickableActor::BeginPlay()
{
    Super::BeginPlay();

    // Накидываем динамический материал
    DynamicMaterialInst = UMaterialInstanceDynamic::Create(ConstantMaterialInst, StaticMeshComponent);
    StaticMeshComponent->SetMaterial(0, DynamicMaterialInst);

}

void ACubeClickableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}