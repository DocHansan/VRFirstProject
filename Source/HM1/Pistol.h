// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Components/PointLightComponent.h"
#include "Pistol.generated.h"

UCLASS()
class HM1_API APistol : public ABaseActor, public IPickableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APistol();

	UMaterialInstanceConstant* ConstantMaterialInstSnow;
	UMaterialInstanceConstant* ConstantMaterialInstGrass;

	UPhysicalMaterial* PhysicalMaterial;

	UPointLightComponent* PointLightComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ChangeMatToSnow();

	UFUNCTION(BlueprintCallable)
	void ChangeMatToGrass();
};
