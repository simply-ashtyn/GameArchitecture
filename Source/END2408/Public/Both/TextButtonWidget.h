// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TextButtonWidget.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClicked);

UCLASS()
class END2408_API UTextButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativePreConstruct();
	void NativeConstruct();
	FOnButtonClicked OnButtonClicked;
	UFUNCTION(BlueprintCallable)
	void HandleButtonClick();

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UButton* BackgroundButton;	
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UTextBlock* Information;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	FText Info;
};