// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/BTTask_Wander.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Wander::UBTTask_Wander()
{
	Radius = 1000.f;
	LocationName = "Location";
}

EBTNodeResult::Type UBTTask_Wander::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AActor* Owner = OwnerComp.GetOwner();
	FVector OwnerLocation = Owner->GetActorLocation();
	UNavigationSystemV1* NavMesh = UNavigationSystemV1::GetCurrent(GetWorld());
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	FNavLocation ResultLocation;
	bool LocationFound = NavMesh->GetRandomPointInNavigableRadius(OwnerLocation, Radius, ResultLocation);
	if (LocationFound)
	{
		Blackboard->SetValueAsVector(LocationName, ResultLocation.Location);
		return EBTNodeResult::Succeeded;
	}
	else
		return EBTNodeResult::Failed;
}
