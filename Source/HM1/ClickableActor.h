// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "ClickableActor.generated.h"

/**
 * 
 */
UCLASS()
class HM1_API AClickableActor : public ABaseActor, public IClickableInterface
{
	GENERATED_BODY()
	
public:

    AClickableActor();

    void Click_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
