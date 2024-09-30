// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimation.generated.h"

/**
 *
 */
UCLASS()
class END2408_API UCharacterAnimation : public UAnimInstance {
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
	float Velocity;

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
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
