// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/CharacterAnimation.h"


void UCharacterAnimation::PreviewWindowUpdate_Implementation() {
	HideAttackEvent();
}
void UCharacterAnimation::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();

	if(Pawn) {
		// Is Valid
		Velocity = Pawn->GetVelocity().Size();
		HideSetDirection();
	} else {
		// In Not Valid
		PreviewWindowUpdate();
	}
}
