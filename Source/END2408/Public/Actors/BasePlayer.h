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
	TSubclassOf<class UPlayerHUD> PlayerHUD;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UUserWidget* PlayerHUD_Widget;

	void BeginPlay() override;
	void HandleDeath(float Ratio) override;
	void BindWeaponAndAnimations();
	void BindWeaponAndAnimations_Implementation() override;

public:
	ABasePlayer();
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RemoveUI();
	void RemoveUI_Implementation();

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
};
