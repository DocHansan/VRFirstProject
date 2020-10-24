// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Engine/World.h"
#include "SphereClickableActor.h"
#include "CubeClickableActor.h"
#include "BaseLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class HM1_API ABaseLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
};
