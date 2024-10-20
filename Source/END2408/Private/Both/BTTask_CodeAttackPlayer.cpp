// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/BTTask_CodeAttackPlayer.h"
#include "Actors/AgentController.h"
#include "Both/CodeEnemyInterface.h"
#include "EngineUtils.h"

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
	if (ICodeEnemyInterface* EnemyInterface = Cast<ICodeEnemyInterface>(OwnerComp.GetOwner()))
	{
		EnemyInterface->EnemyAttack();
	}
	WaitForMessage(OwnerComp, FinishedName);
	return EBTNodeResult::Succeeded;
}