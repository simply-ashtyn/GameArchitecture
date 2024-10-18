// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HealthPickup.h"
#include "Particles/ParticleSystemComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Both/Interface_CodePickup.h"
#include "EngineUtils.h"

AHealthPickup::AHealthPickup()
{
	SetActorRelativeScale3D(FVector(1.5f, 1.2f, 2.0f)); //.5 .5 .7
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Health Particle System"));
	ParticleSystem->SetupAttachment(GetRootComponent());
	ParticleSystem->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.7f));
	ParticleSystem->SetRelativeLocation(FVector(0.f, 0.f, -40.f));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> HealthParticleSystem(TEXT("ParticleSystem'/Game/END_Starter/VFX/PulsingHeart/P_Heart_Pulsing.P_Heart_Pulsing'"));
	ParticleSystem->SetTemplate(HealthParticleSystem.Object);

	HealDamage = -1.5f;
}

bool AHealthPickup::CanPickup(AActor* OtherActor)
{
	//interface message!
	if (IInterface_CodePickup* InterfaceCodePickup = Cast<IInterface_CodePickup>(OtherActor))
	{
		return InterfaceCodePickup->CanPickupHealth();
	}
	else
		return false;
}

void AHealthPickup::HandlePostPickup_Implementation()
{
	Destroy();
}

void AHealthPickup::HandleOverlap_Implementation(AActor* OtherActor, FHitResult SweepResult)
{
	UGameplayStatics::ApplyDamage(OtherActor, HealDamage, NULL, this, NULL);
}

//void AHealthPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	OtherActor->TakeDamage(HealDamage, HealEvent, GetInstigatorController(), this);
//	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
//}
