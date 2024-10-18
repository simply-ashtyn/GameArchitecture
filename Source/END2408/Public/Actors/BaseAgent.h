// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "Both/CodeEnemyInterface.h"
//#include "Actors/BasePickup.h"
#include "BaseAgent.generated.h"

/**
 * 
 */
UCLASS()
class END2408_API ABaseAgent : public ABaseCharacter, public ICodeEnemyInterface
{
	GENERATED_BODY()
	
public:
	ABaseAgent();
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	//void OnPlayerDeath();

	//------------------------------------//
	// ICodeEnemyInterface
	//------------------------------------//	
	
	virtual void EnemyAttack() override;
	virtual void EnemyReload() override;
	
	//------------------------------------//
	// ICodeEnemyInterface
	//------------------------------------//
	
protected:
	void BeginPlay() override;
	FName AmmoName;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	class UBlackboardComponent* Blackboard;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ActionEnded();
	virtual void ActionEnded_Implementation();
	//bool CanPickup(AActor* OtherActor) override; ///IS DONE WITH INTERFACE
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UpdateBlackboardAmmo(float current, float max);
	virtual void UpdateBlackboardAmmo_Implementation(float current, float max);

private:
	void AIReload();
	void AIReload_Implementation();
	//void Shoot();
	//void Shoot_Implementation() override;
};
