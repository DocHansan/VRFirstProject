// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "ClickableInterface.h"
#include "PickableInterface.h"
#include "PickableActor.generated.h"

/**
 * 
 */
UCLASS()
class HM1_API APickableActor : public ABaseActor, public IClickableInterface, public IPickableInterface
{
	GENERATED_BODY()
	
public:

	APickableActor();

	void Click_Implementation();

	void Pick_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
