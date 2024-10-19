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
	void NativeContruct();

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextButtonWidget* PlayButton;	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextButtonWidget* QuitButton;

private:
	UGameInstance* GameInstance;
	UCodeGameInstance* CodeGameInstance;
};
