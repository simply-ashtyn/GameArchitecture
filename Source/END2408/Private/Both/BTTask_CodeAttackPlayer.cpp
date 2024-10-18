// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/BTTask_CodeAttackPlayer.h"
#include "Actors/AgentController.h"

UBTTask_CodeAttackPlayer::UBTTask_CodeAttackPlayer()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
	bCreateNodeInstance = false;
	NodeName = "AttackPlayer";
	FinishedName = "ActionFinished";
}

EBTNodeResult::Type UBTTask_CodeAttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemor)
{
	if (auto owningController = Cast<AAgentController>(OwnerComp.GetAIOwner()))
	{
		//owningController->EnemyAttack(); //need to call interface attack player
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}