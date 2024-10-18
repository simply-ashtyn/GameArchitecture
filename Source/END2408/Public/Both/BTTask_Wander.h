// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Wander.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API UBTTask_Wander : public UBTTaskNode
{
	GENERATED_BODY()

	UBTTask_Wander();
	
	UPROPERTY(EditAnywhere, Category = Default)
	FName LocationName;
	UPROPERTY(EditAnywhere, Category = Default)
	float Radius;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
