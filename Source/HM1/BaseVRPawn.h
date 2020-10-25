// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "MotionControllerComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
//#include "HeadMountedDisplay.h"
#include "BaseVRPawn.generated.h"

UCLASS(Abstract)
class HM1_API ABaseVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseVRPawn();

	UPROPERTY(EditAnywhere)
	UMotionControllerComponent* ControllerLeft;

	UPROPERTY(EditAnywhere)
	UMotionControllerComponent* ControllerRight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeleportVisualizing)
	bool bAfterPressingTheButton;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void StartChangeColorLeft();
	void StopChangeColorLeft();
	void StartChangeColorRight();
	void StopChangeColorRight();

	UPROPERTY(BlueprintReadWrite)
	bool bIsNeedChangeColorLeft;

	UPROPERTY(BlueprintReadWrite)
	bool bIsNeedChangeColorRight;

};
