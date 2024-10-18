// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Reload.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API UBTTask_Reload : public UBTTaskNode
{
	GENERATED_BODY()
	
	UBTTask_Reload();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UPROPERTY(EditAnywhere, Category = Default)
	FName FinishedName;
};
