// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/CodeMainMenuWidget.h"
#include "Both/CodeGameInstance.h"
#include "Both/TextButtonWidget.h"
#include "Components/Button.h"
#include "../END2408.h"

void UCodeMainMenuWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	GameInstance = GetGameInstance();
	CodeGameInstance = Cast<UCodeGameInstance>(GameInstance);
	if (CodeGameInstance == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("NEED TO SET GAME INSTANCE TO BLUEPRINT VERSION"));
	}
}

void UCodeMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//PlayButton->UsableButton->OnClicked.AddDynamic(CodeGameInstance, &UCodeGameInstance::LoadFirstLevel);
	PlayGameButton->OnButtonClicked.AddDynamic(CodeGameInstance, &UCodeGameInstance::LoadFirstLevel);
	QuitButton->OnButtonClicked.AddDynamic(CodeGameInstance, &UCodeGameInstance::QuitGame);
}
