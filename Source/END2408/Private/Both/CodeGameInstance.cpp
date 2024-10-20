// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/CodeGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../END2408.h"

UCodeGameInstance::UCodeGameInstance()
{
	FirstLevelIndex = 1;
	GameLevels = TArray<FName> { "CodeMainMenu","CodeTestingMap" };
}

void UCodeGameInstance::LoadFirstLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), GameLevels[FirstLevelIndex]);
	// set input mode UI only
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerController->SetInputMode(FInputModeGameOnly());
}

void UCodeGameInstance::QuitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}

void UCodeGameInstance::LoadCurrentLevel()
{
	LoadLevelSafe(CurrentLevelIndex);
}

void UCodeGameInstance::LoadMainMenu()
{
	LoadLevelSafe(0);
}

void UCodeGameInstance::LoadLevelSafe(int LevelIndex)
{
	if (GameLevels.IsValidIndex(LevelIndex))
	{
		LoadFirstLevel();
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Could not load level index %n invalid index"), LevelIndex);
	}
}
