// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereClickableActor.h"

ASphereClickableActor::ASphereClickableActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // ���������� ��� �����
    static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
    StaticMeshComponent->SetStaticMesh(SphereMesh.Object);

    // ���������� ����������� ��������
    static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant>Material(TEXT("/Game/Materials/ColorInst.ColorInst"));
    ConstantMaterialInst = Material.Object;
    StaticMeshComponent->SetMaterial(0, ConstantMaterialInst);
}

void ASphereClickableActor::BeginPlay()
{
    Super::BeginPlay();

    // ���������� ������������ ��������
    DynamicMaterialInst = UMaterialInstanceDynamic::Create(ConstantMaterialInst, StaticMeshComponent);
    StaticMeshComponent->SetMaterial(0, DynamicMaterialInst);
}

void ASphereClickableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}