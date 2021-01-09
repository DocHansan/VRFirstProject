// Fill out your copyright notice in the Description page of Project Settings.


#include "CubePickableActor.h"

ACubePickableActor::ACubePickableActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Накидываем меш сферы
    static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("/Game/Meshes/CubeMesh_1.CubeMesh_1"));
    StaticMeshComponent->SetStaticMesh(SphereMesh.Object);

    // Накидываем статический материал
    static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant>Material(TEXT("/Game/Materials/Gold2_Inst.Gold2_Inst"));
    ConstantMaterialInst = Material.Object;
    StaticMeshComponent->SetMaterial(0, ConstantMaterialInst);

    static ConstructorHelpers::FObjectFinder<UPhysicalMaterial>PhysMaterial(TEXT("/Game/Materials/CubePhysicalMaterial.CubePhysicalMaterial"));
    PhysicalMaterial = PhysMaterial.Object;
    StaticMeshComponent->SetPhysMaterialOverride(PhysicalMaterial);

    // Change mass
    StaticMeshComponent->SetMassOverrideInKg(NAME_None, 25.f);
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
