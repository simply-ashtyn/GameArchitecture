// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AgentController.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API AAgentController : public AAIController
{
	GENERATED_BODY()
	
public:
	AAgentController();
	void OnPossess(APawn* PossessedPawn) override;

protected:
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
		class UBehaviorTree* BehaviorTree;
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
		class UAIPerceptionComponent* AIPerceptionComp;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
		FName PlayerName;

	class UAIPerceptionSystem* perceptionSystem;

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void TargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	void TargetPerceptionUpdated_Implementation(AActor* Actor, FAIStimulus Stimulus);
};
