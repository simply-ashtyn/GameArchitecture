// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DamagePickup.h"
#include "Engine/DamageEvents.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API AHealthPickup : public ADamagePickup
{
	GENERATED_BODY()
	
public:
	AHealthPickup();

protected:
	bool CanPickup(AActor* OtherActor) override;
	virtual void HandlePostPickup_Implementation();
	void HandleOverlap_Implementation(AActor* OtherActor, FHitResult SweepResult) override;
	//virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HealDamage;

private:
	//FDamageEvent HealEvent;
};
