// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AgentController.h"
#include "Perception/AIPerceptionSystem.h"
#include "Actors/BaseCharacter.h"
#include "Perception/AISenseConfig_Sight.h"
#include "../END2408.h"

AAgentController::AAgentController()
{
	PlayerName = "Player";
	BTAsset = nullptr;
	
	/// Config Sight
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 900;
	SightConfig->LoseSightRadius = 1100;
	SightConfig->PeripheralVisionAngleDegrees = 40;
	FAISenseAffiliationFilter SenseFilter;
	SenseFilter.bDetectNeutrals = 1;
	SenseFilter.bDetectEnemies = 0;
	SenseFilter.bDetectFriendlies = 0;
	SightConfig->DetectionByAffiliation = SenseFilter;

	/// Config Perception Comp
	AIPerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComp"));
	AIPerceptionComp->ConfigureSense(*SightConfig);
	AIPerceptionComp->SetDominantSense(SightConfig->GetSenseImplementation());
	//SetPerceptionComponent(*AIPerceptionComp);
	//GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AAgentController::TargetPerceptionUpdated);
}

void AAgentController::OnPossess(APawn* PossessedPawn)
{
	Super::OnPossess(PossessedPawn);
	if (BTAsset != nullptr)
	{
		RunBehaviorTree(BTAsset);
	}
	else
		UE_LOG(Game, Error, TEXT("Behavior Tree Asset Not Set"));
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