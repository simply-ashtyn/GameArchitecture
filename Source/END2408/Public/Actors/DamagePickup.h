// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BasePickup.h"
#include "DamagePickup.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API ADamagePickup : public ABasePickup
{
	GENERATED_BODY()
	
public:
	ADamagePickup();
	UPROPERTY(VisibleDefaultsOnly)
	class UParticleSystemComponent* ParticleSystem;

protected:
	virtual void BeginPlay() override;
	
	void HandleOverlap_Implementation(AActor* OtherActor, FHitResult SweepResult) override;
	void HandlePostPickup_Implementation() override;
	float BaseDamage;

private:
	
};
