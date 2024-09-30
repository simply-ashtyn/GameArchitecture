// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"

ABasePlayer::ABasePlayer() {
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetRelativeLocation(FVector(0., 0., 60.));
	SpringArm->SetupAttachment(GetRootComponent() /*, Not needed unless we havce to set something by it's SOCKET'*/);
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	//Always call your parent
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind Rotation Function(s)
	PlayerInputComponent->BindAxis("TurnRight", this, &ABasePlayer::AddControllerYawInput);

	// Bind Movenent Function(s)
	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayer::InputAxisMoveForward);
}

void ABasePlayer::InputAxisMoveForward(float AxisValue) {
	AddMovementInput(FRotator(0., GetControlRotation().Yaw, 0.).Vector(), AxisValue);
}
