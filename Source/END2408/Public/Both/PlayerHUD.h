// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

/**
 *
 */
UCLASS()
class END2408_API UPlayerHUD : public UUserWidget {
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UProgressBar* HealthBar;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* CurrentAmmoText;	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* MaxAmmoText;

public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void CodeSetAmmo(float CurrentAmmo,float MaxAmmo);
	virtual void CodeSetAmmo_Implementation(float CurrentAmmo,float MaxAmmo);	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void CodeSetHealth(float Percent);
	virtual void CodeSetHealth_Implementation(float Percent);
};
