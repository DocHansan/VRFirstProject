// Fill out your copyright notice in the Description page of Project Settings.


#include "SpherePickableActor.h"

ASpherePickableActor::ASpherePickableActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Накидываем меш сферы
    static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
    StaticMeshComponent->SetStaticMesh(SphereMesh.Object);

    // Накидываем статический материал
    static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant>Material(TEXT("/Game/Materials/Gold3_Inst.Gold3_Inst"));
    ConstantMaterialInst = Material.Object;
    StaticMeshComponent->SetMaterial(0, ConstantMaterialInst);

    static ConstructorHelpers::FObjectFinder<UPhysicalMaterial>PhysMaterial(TEXT("/Game/Materials/CubePhysicalMaterial.CubePhysicalMaterial"));
    PhysicalMaterial = PhysMaterial.Object;
    StaticMeshComponent->SetPhysMaterialOverride(PhysicalMaterial);

    // Change mass
    StaticMeshComponent->SetMassOverrideInKg(NAME_None, 50.f);
}

void ASpherePickableActor::BeginPlay()
{
    Super::BeginPlay();

    // Накидываем динамический материал
    DynamicMaterialInst = UMaterialInstanceDynamic::Create(ConstantMaterialInst, StaticMeshComponent);
    StaticMeshComponent->SetMaterial(0, DynamicMaterialInst);
}

void ASpherePickableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}