// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CodeMainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API UCodeMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativePreConstruct();
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextButtonWidget* PlayGameButton;	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextButtonWidget* QuitButton;

private:
	UGameInstance* GameInstance;
	UCodeGameInstance* CodeGameInstance;
};
