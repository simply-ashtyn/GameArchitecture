// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"


#include "BasePlayer.generated.h" //must be last include in header

//class USpringArmComponent;

/**
 *
 */
UCLASS()
class END2408_API ABasePlayer : public ABaseCharacter {
	GENERATED_BODY()

protected:
	class USpringArmComponent* SpringArm;
public:
	ABasePlayer();
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void InputAxisMoveForward(float AxisValue);
};
