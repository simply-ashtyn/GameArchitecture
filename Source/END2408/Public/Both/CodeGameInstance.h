// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <array>
#include "CodeGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API UCodeGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UCodeGameInstance();

	UFUNCTION(BlueprintCallable)
	void LoadFirstLevel();
	UFUNCTION(BlueprintCallable)
	void QuitGame();	
	UFUNCTION(BlueprintCallable)
	void LoadCurrentLevel();
	UFUNCTION(BlueprintCallable)
	void LoadMainMenu();

	int FirstLevelIndex;
	int CurrentLevelIndex;
	TArray<FName> GameLevels;

private:
	void LoadLevelSafe(int LevelIndex);
};
