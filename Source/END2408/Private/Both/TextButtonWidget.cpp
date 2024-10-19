// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/TextButtonWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UTextButtonWidget::NativePreConstruct()
{
	Information->SetText(Info);
}

void UTextButtonWidget::NativeConstruct()
{
	BackgroundButton->OnClicked.AddDynamic(this, &UTextButtonWidget::HandleButtonClick);
}

void UTextButtonWidget::HandleButtonClick()
{
	OnButtonClicked.Broadcast();
}