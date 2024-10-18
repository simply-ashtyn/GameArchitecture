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
class END2408_API ABasePlayer : public ABaseCharacter 
{
	GENERATED_BODY()


protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> PlayerHUD;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UUserWidget* PlayerHUDref;

	void BeginPlay() override;

public:
	ABasePlayer();
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//------------------------------------//
	// IInterface_CodePickup
	//------------------------------------//	

	virtual bool CanPickupHealth() override;

	//------------------------------------//
	// IInterface_CodePickup
	//------------------------------------//

private:
	// Player Input Functions
	APlayerController* PlayerController;
	void InputAxisMoveForward(float AxisValue);
	void Strafe(float value);
	void InputReload();
	void HandleDeath(float Percent);
};
