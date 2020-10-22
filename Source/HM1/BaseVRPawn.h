// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseVRPawn.generated.h"

UCLASS(Abstract)
class HM1_API ABaseVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseVRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeleportVisualizing)
	bool bAfterPressingTheButton;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
