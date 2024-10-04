// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Rifle.h"

// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	gunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	SetRootComponent(gunMesh);
	//BulletTemplate = nullptr;
	canShoot = true;
}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARifle::Shoot()
{
	if (canShoot) ///old project note: Returning null??
	{
		FActorSpawnParameters bulletParams;
		bulletParams.Instigator = Cast<APawn>(GetParentActor());
		//AProjectile* bulletInstance = GetWorld()->SpawnActor<AProjectile>(BulletTemplate, gunMesh->GetSocketLocation(TEXT("MuzzleFlashSocket")), bulletParams.Instigator->GetBaseAimRotation(), bulletParams);
	}
}