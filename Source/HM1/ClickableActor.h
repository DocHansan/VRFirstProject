// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "ClickableInterface.h"
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
};
