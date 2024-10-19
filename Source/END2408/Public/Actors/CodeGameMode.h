// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API ACodeGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACodeGameMode();

protected:
	virtual void BeginPlay() override;

};
