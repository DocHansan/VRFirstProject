// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClickableActor.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "CubeClickableActor.generated.h"

/**
 * 
 */
UCLASS()
class HM1_API ACubeClickableActor : public AClickableActor
{
	GENERATED_BODY()
	

public:

	ACubeClickableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UMaterialInstanceConstant* ConstantMaterialInst;

	UMaterialInstanceDynamic* DynamicMaterialInst;

	UPhysicalMaterial* PhysicalMaterial;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
