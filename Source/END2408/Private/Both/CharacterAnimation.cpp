// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/CharacterAnimation.h"
#include "../END2408.h"

UCharacterAnimation::UCharacterAnimation()
{
	ShootNodeName = "Action";
	HurtNodeName = "Action"; //Hurt node name doesn't work, but action does
	ReloadNodeName = "Action";
	DeathNodeName = "Death";
	Velocity = 0;
	//Direction = 0;
	ActionHappening = false;
	DeathAssetIndex = -1;

	debugDeath = false;
	debugHurt = false;
	debugShoot = false;
	debugReload = false;
}

void UCharacterAnimation::AnimationUpdate()
{

}

void UCharacterAnimation::PreviewWindowUpdate_Implementation() {
	HideAttackEvent();
}

void UCharacterAnimation::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();

	if(Pawn != nullptr)
	{
		// Is Valid
		Velocity = Pawn->GetVelocity().Size();
				//Direction = CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());
		HideSetDirection();
		if (!IsPlayingSlotAnimation(ShootAsset,ShootNodeName))
		{
			OnShootEnded.Broadcast();
		}		
		else if (!IsPlayingSlotAnimation(ReloadAsset,ReloadNodeName))
		{
			OnReloadEnded.Broadcast();
		}		
		else if (!IsPlayingSlotAnimation(CurrDeathAsset,DeathNodeName))
		{
			OnDeathEnded.Broadcast();
		}
	} 
	else if (debugShoot)
	{
		PlayShoot();
		debugShoot = false;
	}
	else if (debugHurt)
	{
		PlayHurt(0);
		debugHurt = false;
	}
	else if (debugDeath)
	{
		PlayDeath();
		debugDeath = false;
	}
	else if (debugReload)
	{
		PlayReload();
		debugReload = false;
	}
	else 
	{
		// Is  Not Valid
		PreviewWindowUpdate();
	}
}

void UCharacterAnimation::PlayShoot_Implementation()
{
	PlaySlotAnimationAsDynamicMontage(ShootAsset, ShootNodeName);
}

void UCharacterAnimation::PlayHurt_Implementation(float percent)
{
	PlaySlotAnimationAsDynamicMontage(HurtAsset, HurtNodeName);
}

void UCharacterAnimation::PlayDeath_Implementation()
{
	int32 indexInArray = FMath::RandRange(0, DeathAssets.Num() - 1);
	DeathAssetIndex = indexInArray;
	CurrDeathAsset = DeathAssets[indexInArray];
	GetWorld()->GetTimerManager().SetTimer(TimeHandle, this, &UCharacterAnimation::DeathEnded, CurrDeathAsset->GetPlayLength());
	//PlayDeath();
}

void UCharacterAnimation::PlayReload_Implementation()
{
	UE_LOG(Game, Error, TEXT("Reloading from Animation"));
	PlaySlotAnimationAsDynamicMontage(ReloadAsset, ReloadNodeName);
}

void UCharacterAnimation::DeathEnded()
{
	OnDeathEnded.Broadcast();
}
