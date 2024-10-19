// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/PlayerHUD.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"

void UPlayerHUD::CodeSetAmmo_Implementation(float CurrentAmmo, float MaxAmmo)
{
	FString TempString = FString::SanitizeFloat(CurrentAmmo);
	CurrentAmmoText->SetText(FText::FromString(TempString));

	TempString = FString::SanitizeFloat(MaxAmmo);
	MaxAmmoText->SetText(FText::FromString(TempString));
}

void UPlayerHUD::CodeSetHealth_Implementation(float Percent)
{
	HealthBar->SetPercent(Percent);
}
