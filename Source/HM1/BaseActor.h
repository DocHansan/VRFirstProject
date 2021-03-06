// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"
#include "ClickableInterface.h"
#include "PickableInterface.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Components/PrimitiveComponent.h"
#include "BaseActor.generated.h"

UENUM(Meta = (Bitflags))
enum class EActorColor : uint8
{
	ECB_Red = 0x00           UMETA(DisplayName = "Red"),
	ECB_Green = 0x01        UMETA(DisplayName = "Green"),
	ECB_Blue = 0x02      UMETA(DisplayName = "Blue"),
};

//ENUM_CLASS_FLAGS(EActorColor)

UCLASS(Abstract)
class HM1_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, Meta = (Bitmask, BitmaskEnum = "EActorColor"), Category = Color)
	//TEnumAsByte<EActorColor> ActorColor;
	uint8 ActorColor;

	UPROPERTY(EditAnywhere, Category = Color, Meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float RedIntensity;

	UPROPERTY(EditAnywhere, Category = Color, Meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float GreenIntensity;

	UPROPERTY(EditAnywhere, Category = Color, Meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float BlueIntensity;

	UFUNCTION(BlueprintCallable)
	FVector ChangeColor();

	UPROPERTY(BlueprintReadWrite)
	FVector Color;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
