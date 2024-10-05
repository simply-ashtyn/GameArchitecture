// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AgentController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Actors/BaseCharacter.h"

AAgentController::AAgentController()
{
	PlayerName = "Player";
	BehaviorTree = nullptr;
	AIPerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComp"));
	SetPerceptionComponent(*AIPerceptionComp);
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AAgentController::TargetPerceptionUpdated);
}

void AAgentController::OnPossess(APawn* PossessedPawn)
{
	Super::OnPossess(PossessedPawn);
	if (BehaviorTree != nullptr)
	{
		RunBehaviorTree(BehaviorTree);
	}
}

void AAgentController::TargetPerceptionUpdated_Implementation(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		Blackboard->SetValueAsObject(PlayerName, Actor);
	}
	else
	{
		Blackboard->ClearValue(PlayerName);
	}
}
