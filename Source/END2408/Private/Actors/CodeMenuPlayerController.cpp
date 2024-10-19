// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CodeMenuPlayerController.h"
#include "Both/CodeMainMenuWidget.h"
#include "Actors/BasePlayer.h"
#include "Blueprint/UserWidget.h"
#include "../END2408.h"
#include <Kismet/GameplayStatics.h>

ACodeMenuPlayerController::ACodeMenuPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	MenuClass = nullptr;
}

void ACodeMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//create widget
	if (IsValid(MenuClass))
	{
		MenuClass_Widget = Cast<UCodeMainMenuWidget>(CreateWidget(GetWorld(), MenuClass));
		// add to viewport
		if (MenuClass_Widget != nullptr)
		{
			MenuClass_Widget->AddToViewport();
		}
	}

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// set input mode UI only
	PlayerController->SetInputMode(FInputModeUIOnly());
	//FInputodeGameAndUI::SetWidgetToFocus()
}

void ACodeMenuPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}