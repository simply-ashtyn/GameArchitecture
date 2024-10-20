// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CodeGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "../END2408.h"
#include "EngineUtils.h"
#include "Actors/BaseCharacter.h"
#include "Actors/BasePlayer.h"
#include "Both/ResultsWidget.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"

ACodeGameMode::ACodeGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Code/Actors/BP_CodeBasePlayer"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassFinder(TEXT("/Game/Code/Actors/CodeMenuPlayerController"));
	PlayerControllerClass = PlayerControllerClassFinder.Class;
}

void ACodeGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(Game, Warning, TEXT("GameMode has started"));

	for (TActorIterator<ABaseCharacter> itr(GetWorld()); itr; ++itr)
	{
		if (Cast<ABasePlayer>(*itr))
		{
			Player = Cast<ABasePlayer>(*itr);
			Player->OnPlayerLost.AddDynamic(this, &ACodeGameMode::RemovePlayer);
		}
		else
		{
			AddEnemy(*itr);
		}

		PlayerController = Cast<APlayerController>(Player->GetController());
		if (IsValid(ResultsWidgetClass))
		{
			ResultsWidgetClass_Widget = CreateWidget<UResultsWidget>(GetWorld(), ResultsWidgetClass);
		}
	}
}

void ACodeGameMode::AddEnemy(AActor* Agent)
{
	Agent->OnDestroyed.AddDynamic(this, &ACodeGameMode::RemoveEnemy);
	NumberOfEnemies++;
}

void ACodeGameMode::RemovePlayer()
{
	AddWidgetToViewPort();
	PlayerController->SetInputMode(FInputModeUIOnly().SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways)); //EMouseLockMode::LockAlways
}

void ACodeGameMode::RemoveEnemy(AActor* Agent)
{
	NumberOfEnemies--;
	if (NumberOfEnemies < 0)
	{
		AddWidgetToViewPort();
	}
	ResultsWidgetClass_Widget->SetWin();
	Player->PlayerWin();
}

void ACodeGameMode::AddWidgetToViewPort()
{
	if (ResultsWidgetClass_Widget != nullptr)
	{
		ResultsWidgetClass_Widget->AddToViewport();
	}
}
