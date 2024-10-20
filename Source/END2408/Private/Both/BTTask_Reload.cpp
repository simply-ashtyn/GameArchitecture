// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/BTTask_Reload.h"
#include "Both/CodeEnemyInterface.h"
#include "EngineUtils.h"

UBTTask_Reload::UBTTask_Reload()
{
	FinishedName = "ActionFinished";
}

EBTNodeResult::Type UBTTask_Reload::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ICodeEnemyInterface* EnemyInterface = Cast<ICodeEnemyInterface>(OwnerComp.GetOwner()))
	{
		EnemyInterface->EnemyReload();
	}
	WaitForMessage(OwnerComp, FinishedName);
	return EBTNodeResult::Succeeded;
}
