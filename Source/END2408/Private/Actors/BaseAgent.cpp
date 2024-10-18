// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseAgent.h"
#include "Actors/Rifle.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Actors/AgentController.h"
#include "../END2408.h"
#include "EngineUtils.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>

ABaseAgent::ABaseAgent()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
	AmmoName = "Ammo";
}

void ABaseAgent::BeginPlay()
{
	AAIController* AgentController = Cast<AAgentController>(GetController());
	if (AgentController != nullptr)
	{
		Blackboard = AgentController->GetBlackboardComponent();
		if (Blackboard == nullptr)
			UE_LOG(Game, Error, TEXT("Could not get the Blackboard from the AI Controller"));
	}
	else
		UE_LOG(Game, Error, TEXT("Could not get the AI Controller"));
	Super::BeginPlay();
}

void ABaseAgent::ActionEnded_Implementation()
{
	UAIBlueprintHelperLibrary::SendAIMessage(this, FName("ActionFinished"), NULL);
}

void ABaseAgent::AIReload_Implementation()
{
	Gun->RequestReload();
}

//void ABaseAgent::Shoot_Implementation()
//{
//}

void ABaseAgent::UpdateBlackboardAmmo_Implementation(float current, float max)
{
	Blackboard->SetValueAsFloat(AmmoName, current);
}

//void ABaseAgent::OnPlayerDeath()
//{
//
//}

void ABaseAgent::EnemyAttack()
{
	UE_LOG(Game, Error, TEXT("In C++ EnemyAttack"));
	Gun->Shoot();
}

void ABaseAgent::EnemyReload()
{
	Reload();
}
