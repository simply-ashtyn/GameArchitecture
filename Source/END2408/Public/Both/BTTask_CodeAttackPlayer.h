// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_CodeAttackPlayer.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API UBTTask_CodeAttackPlayer : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_CodeAttackPlayer();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,uint8* NodeMemor) override;

	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector BlackboardKey;
	FName FinishedName;
};
