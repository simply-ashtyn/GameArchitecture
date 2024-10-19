// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHurt, float, Percent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeath, float, Ratio);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeal, float, Percent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class END2408_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float maxHealth;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float currentHealth;

	/// DELEGATES
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Event Dispatcher")
	FOnHurt OnHurt;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Event Dispatcher")
	FOnDeath OnDeath;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Event Dispatcher")
	FOnHeal OnHeal;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void HandleTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigateBy, AActor* DamageCauser);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	class ABaseCharacter* character;
	class UCharacterAnimation* Animator;
};
