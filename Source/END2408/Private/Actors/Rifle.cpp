// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Rifle.h"
//#include "Both/CharacterAnimation.h"
#include "Components/SkeletalMeshComponent.h"
#include "../END2408.h"
//#include "Actors/BaseCharacter.h"

// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	gunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	SetRootComponent(gunMesh);
	BulletTemplate = nullptr;
	maxAmmo = 5;
	ActionHappening = false;
	IsDead = false;
}

void ARifle::ActionEnded()
{
	ActionHappening = false;
}

void ARifle::OwnerDead()
{
	IsDead = true;
}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
	AActor* Parent = GetParentActor();
	PawnOwner = CastChecked<APawn>(Parent);
	ReloadAmmo();
	//character = CastChecked<ABaseCharacter>(Parent);
	//UAnimInstance* AnimInstance = character->GetMesh()->GetAnimInstance();
	//Animator = CastChecked<UCharacterAnimation>(AnimInstance);
}

// Called every frame
void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AProjectile* ARifle::Shoot_Implementation()
{
	if (CanShoot())
	{
		FActorSpawnParameters bulletParams;
		bulletParams.Instigator = PawnOwner;
		AProjectile* bulletInstance = GetWorld()->SpawnActor<AProjectile>(BulletTemplate, gunMesh->GetSocketLocation(TEXT("MuzzleFlashSocket")), bulletParams.Instigator->GetBaseAimRotation(), bulletParams);
		UseAmmo();
		ActionHappening = true;
		OnAttack.Broadcast();
		return bulletInstance;
	}
	else
		return nullptr;
}

void ARifle::ReloadAmmo()
{
	UE_LOG(Game, Error, TEXT("Reloading from Rifle"));
	currentAmmo = maxAmmo;
	OnAmmoChanged.Broadcast(currentAmmo,maxAmmo);
}

bool ARifle::RequestReload() /// NEED TO CHANGE BACK TO VOID AFTER GETTING ANIMNOTIFY WORKING
{
	UE_LOG(Game, Error, TEXT("Reloading"));
	if (!ActionHappening)
	{
		ActionHappening = true;
		OnReloadAnim.Broadcast();
		ReloadAmmo();
		return true;
	}
	else
	{
		return false;
	}
}

bool ARifle::CanShoot() const
{
	if (!ActionHappening && !IsDead && currentAmmo > 0)
	{
		return true;
	}
	else
		return false;
}

void ARifle::UseAmmo()
{
	currentAmmo -= 1;
	OnAmmoChanged.Broadcast(currentAmmo,maxAmmo);
}
