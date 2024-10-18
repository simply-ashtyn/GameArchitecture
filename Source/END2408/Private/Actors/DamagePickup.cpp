// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DamagePickup.h"
#include "Particles/ParticleSystemComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "../END2408.h"

ADamagePickup::ADamagePickup()
{
	SetActorRelativeScale3D(FVector(1.5f, 1.2f, 2.0f)); //.5 .5 .7
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Damage Particle System"));
	ParticleSystem->SetupAttachment(GetRootComponent());
	ParticleSystem->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.7f));
	ParticleSystem->SetRelativeLocation(FVector(0.f, 0.f, -40.f));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> DamageParticleSystem(TEXT("ParticleSystem'/Game/END_Starter/VFX/Fire/P_Fire'"));
	ParticleSystem->SetTemplate(DamageParticleSystem.Object);

	BaseDamage = 2;
}

void ADamagePickup::BeginPlay()
{
	Super::BeginPlay();
}

void ADamagePickup::HandleOverlap_Implementation(AActor* OtherActor, FHitResult SweepResult)
{
	UE_LOG(Game, Log, TEXT("Took Damage"));
	Super::HandleOverlap_Implementation(OtherActor, SweepResult);
	UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, NULL, this, NULL);
}

void ADamagePickup::HandlePostPickup_Implementation()
{
	//Do Nothing
}