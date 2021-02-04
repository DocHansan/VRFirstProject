// Fill out your copyright notice in the Description page of Project Settings.


#include "Pistol.h"

// Sets default values
APistol::APistol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Ќакидываем меш пистолета
    static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("/Game/Meshes/Pistol.Pistol"));
    StaticMeshComponent->SetStaticMesh(SphereMesh.Object);
    StaticMeshComponent->SetWorldScale3D(FVector(35.f, 35.f, 35.f));

    // Ќакидываем статический материал
    static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant>Material(TEXT("MaterialInstanceConstant'/Game/Materials/Pistol1_Inst.Pistol1_Inst'"));
    ConstantMaterialInstSnow = Material.Object;
    StaticMeshComponent->SetMaterial(0, ConstantMaterialInstSnow);

    //материал grass
    static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant>Material1(TEXT("MaterialInstanceConstant'/Game/Materials/Pistol1_Grass_Inst.Pistol1_Grass_Inst'"));
    ConstantMaterialInstGrass = Material1.Object;

    /*
    static ConstructorHelpers::FObjectFinder<UPhysicalMaterial>PhysMaterial(TEXT("/Game/Materials/CubePhysicalMaterial.CubePhysicalMaterial"));
    PhysicalMaterial = PhysMaterial.Object;
    StaticMeshComponent->SetPhysMaterialOverride(PhysicalMaterial);
    */

    // Change mass
    StaticMeshComponent->SetMassOverrideInKg(NAME_None, 1.f);

    // точечный свет
    //PointLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));
    //PointLightComponent->SetRelativeLocationAndRotation(FVector(-0.5f, -0.2f, 0.f), FRotator(0.f, 0.f, 0.f));
    //PointLightComponent->AttachTo(StaticMeshComponent);
}

// Called when the game starts or when spawned
void APistol::BeginPlay()
{
	//Super::BeginPlay();
	
}

// Called every frame
void APistol::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

}

void APistol::ChangeMatToSnow()
{
    StaticMeshComponent->SetMaterial(0, ConstantMaterialInstSnow);
}

void APistol::ChangeMatToGrass()
{
    StaticMeshComponent->SetMaterial(0, ConstantMaterialInstGrass);
}