// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimation.generated.h"

/**
 *
 */

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShootEnded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathEnded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReloadEnded);

UCLASS()
class END2408_API UCharacterAnimation : public UAnimInstance {
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
	float Velocity;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Direction;*/

	///Animation Assets
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Animation)
	class UAnimSequenceBase* ShootAsset;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Animation)
	class UAnimSequenceBase* HurtAsset;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Animation)
	class UAnimSequenceBase* ReloadAsset;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Animation)
	TArray<class UAnimSequenceBase*> DeathAssets;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Animation)
	class UAnimSequenceBase* CurrDeathAsset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Animation)
	int DeathAssetIndex;

	///Animation Debugs
	UPROPERTY(BluePrintReadWrite, VisibleAnywhere)
	bool debugShoot;
	UPROPERTY(BluePrintReadWrite, VisibleAnywhere)
	bool debugHurt;	
	UPROPERTY(BluePrintReadWrite, EditInstanceOnly)
	bool debugDeath;
	UPROPERTY(BluePrintReadWrite, VisibleAnywhere)
	bool debugReload;

	UFUNCTION()
	void AnimationUpdate();

	UFUNCTION(BlueprintNativeEvent)
	void PreviewWindowUpdate();
	virtual void PreviewWindowUpdate_Implementation();

	//----------------------------------------------------------------------//
	// These functions should not be exported they are used to take the events out of the blueprint
	//----------------------------------------------------------------------//
	UFUNCTION(BlueprintImplementableEvent, Category = "ShouldBeInCode|GoInPreviewWindowUpdate")
	bool HideSetDirection();
	UFUNCTION(BlueprintImplementableEvent, Category = "ShouldBeInCode|GoInPreviewWindowUpdate")
	bool HideAttackEvent();
	UFUNCTION(BlueprintImplementableEvent, Category = "ShouldBeInCode|GoInPreviewWindowUpdate")
	bool HideHurtEvent();
	UFUNCTION(BlueprintImplementableEvent, Category = "ShouldBeInCode|GoInPreviewWindowUpdate")
	bool HideDeathEvent();
	//----------------------------------------------------------------------//
	// These functions should not be exported they are used to take the events out of the blueprint
	//----------------------------------------------------------------------//

public:
	UCharacterAnimation();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	FOnShootEnded OnShootEnded;
	FOnDeathEnded OnDeathEnded;
	FOnReloadEnded OnReloadEnded;

	bool ActionHappening;

	UPROPERTY()
	class UAnimNotify* AnimNotifier;

	FName ShootNodeName;
	FName HurtNodeName;
	FName ReloadNodeName;
	FName DeathNodeName;
	FTimerHandle TimeHandle;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void PlayShoot();
	virtual void PlayShoot_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PlayHurt(float percent);
	virtual void PlayHurt_Implementation(float percent);	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PlayDeath();
	virtual void PlayDeath_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PlayReload();
	virtual void PlayReload_Implementation();

	UFUNCTION()
	void DeathEnded();
};
