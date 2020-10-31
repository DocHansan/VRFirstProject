// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "MotionControllerComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Components/CapsuleComponent.h"
//#include "UObject/NameTypes.h"
//#include "HeadMountedDisplay.h"
#include "BaseVRPawn.generated.h"

UCLASS(Blueprintable, Blueprintable)
class HM1_API ABaseVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseVRPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMotionControllerComponent* ControllerLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMotionControllerComponent* ControllerRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CollisionLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CollisionRight;

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

	UPROPERTY(BlueprintReadWrite)
	bool bIsOverlappingNow;

	UPROPERTY(BlueprintReadWrite)
	UPrimitiveComponent* OverlappingComponent;

	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
