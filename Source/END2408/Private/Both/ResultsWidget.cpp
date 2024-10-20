// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/ResultsWidget.h"
#include "Both/TextButtonWidget.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Both/CodeGameInstance.h"
#include "Components/WidgetSwitcher.h"
#include "../END2408.h"

void UResultsWidget::NativeConstruct()
{
	TimeToMenu = 2.f;
	GameInstance = GetGameInstance();
	CodeGameInstance = Cast<UCodeGameInstance>(GameInstance);
	if (CodeGameInstance == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("NEED TO SET GAME INSTANCE TO BLUEPRINT VERSION"));
	}
	else
	{
		RestartButton->OnButtonClicked.AddDynamic(CodeGameInstance,&UCodeGameInstance::LoadCurrentLevel);
		MenuButton->OnButtonClicked.AddDynamic(CodeGameInstance, &UCodeGameInstance::LoadMainMenu);
	}
}

void UResultsWidget::SetWin()
{
	ButtonArea->SetVisibility(ESlateVisibility::Hidden);
	ResultsSwitch->SetActiveWidgetIndex(1);
	
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimeToMenu, false, 0.f);
	LoadMainMenu();
}

void UResultsWidget::LoadMainMenu()
{
	MenuButton->OnButtonClicked.Broadcast();
}