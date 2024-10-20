// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API ACodeGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACodeGameMode();
	void AddEnemy(AActor* Agent);

	class ABasePlayer* Player;
	class APlayerController* PlayerController;

	UPROPERTY(EditAnywhere, Category = "WidgetClass")
		TSubclassOf<class UResultsWidget> ResultsWidgetClass;
	UPROPERTY(BlueprintReadWrite, Category = "WidgetClass")
		class UResultsWidget* ResultsWidgetClass_Widget;

protected:
	virtual void BeginPlay() override;

private:
	void RemovePlayer();
	void RemoveEnemy(AActor* Actor);

	int NumberOfEnemies;
	void AddWidgetToViewPort();
};
