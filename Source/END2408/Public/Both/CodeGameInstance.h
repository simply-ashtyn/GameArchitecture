// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CodeGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API UCodeGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void LoadFirstLevel();
	UFUNCTION(BlueprintCallable)
	void QuitGame();
	virtual void Shutdown() override;

private:
	void LoadLevelSafe();
};
