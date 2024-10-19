// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CodeMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API ACodeMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACodeMenuPlayerController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "WidgetClass")
		TSubclassOf<UCodeMainMenuWidget> MenuClass;
	UPROPERTY(BlueprintReadWrite, Category = "WidgetClass")
		class UUserWidget* MenuClass_Widget;
};
