// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Both/Interface_CodePickup.h"
#include "Actors/Rifle.h"
#include "Both/CharacterAnimation.h"
#include "Actors/HealthComponent.h"
#include "BaseCharacter.generated.h"

UCLASS()
class END2408_API ABaseCharacter : public ACharacter, public IInterface_CodePickup
{

	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UChildActorComponent* GunSocket;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ARifle> gunClass;
	class ARifle* Gun;

	UPROPERTY()
	AActor* childActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UHealthComponent* HealthComponent;
	bool isDead;
	UFUNCTION()
	void HandleHurt();
	UFUNCTION()
	void HandleDeath();

	///ANIMATIONS
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void BindWeaponAndAnimations();
	virtual void BindWeaponAndAnimations_Implementation();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCharacterAnimation* Animator;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Shoot();
	virtual void Shoot_Implementation();	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Reload();
	virtual void Reload_Implementation();

	//------------------------------------//
	// IInterface_CodePickup
	//------------------------------------//	

	virtual bool CanPickupHealth() override;

	//------------------------------------//
	// IInterface_CodePickup
	//------------------------------------//

};
