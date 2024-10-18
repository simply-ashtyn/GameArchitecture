// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.h"
#include "Rifle.generated.h"

/// DELEGATES
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChanged, float, current, float, max);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReloadAnim);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttack);


UCLASS()
class END2408_API ARifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARifle();

	/// DELEGATES
	UPROPERTY(BlueprintAssignable,BlueprintCallable, Category = "Event Dispatcher")
	FOnAttack OnAttack;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Event Dispatcher")
	FOnAmmoChanged OnAmmoChanged;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Event Dispatcher")
	FOnReloadAnim OnReloadAnim;

	/// FUNCTIONS
	UFUNCTION(BlueprintCallable) //for animations
	void ActionEnded();
	UFUNCTION(BlueprintCallable)
	void OwnerDead();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		class USkeletalMeshComponent* gunMesh;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AProjectile> BulletTemplate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		APawn* PawnOwner;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	AProjectile* Shoot();
	virtual AProjectile* Shoot_Implementation();
	void ReloadAmmo();
	float currentAmmo;
	float maxAmmo;
	bool RequestReload();
	bool IsDead;

private:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Function)
	bool CanShoot() const;
	void UseAmmo();
	bool ActionHappening;
	//class ABaseCharacter* character;
	//class UCharacterAnimation* Animator;
};
