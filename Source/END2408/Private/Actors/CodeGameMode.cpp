// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CodeGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "../END2408.h"

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
}