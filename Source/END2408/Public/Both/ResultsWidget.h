// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ResultsWidget.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API UResultsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextButtonWidget* RestartButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextButtonWidget* MenuButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UWidgetSwitcher* ResultsSwitch;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UVerticalBox* ButtonArea;

	UFUNCTION(BlueprintCallable)
	void SetWin();

private:
	UFUNCTION(BlueprintCallable)
	void LoadMainMenu();
	class UGameInstance* GameInstance;
	class UCodeGameInstance* CodeGameInstance;
	float TimeToMenu;
};
