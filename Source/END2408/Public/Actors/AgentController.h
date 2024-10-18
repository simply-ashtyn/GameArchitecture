// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
//#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionTypes.h"
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
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UBehaviorTree* BTAsset;

protected:
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
		class UAIPerceptionComponent* AIPerceptionComp;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
		FName PlayerName;

	class UAISenseConfig_Sight* SightConfig;

	class UAIPerceptionSystem* PerceptionSystem;

	///Throwing tons of errors
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void TargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	void TargetPerceptionUpdated_Implementation(AActor* Actor, FAIStimulus Stimulus);
};
