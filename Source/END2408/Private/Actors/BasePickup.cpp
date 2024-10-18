// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePickup.h"
#include "Components/BoxComponent.h"
#include "../END2408.h"

// Sets default values
ABasePickup::ABasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SetRootComponent(CollisionBox);
}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnOverlapBegin);
}

bool ABasePickup::CanPickup(AActor* OtherActor)
{
	return true;
}

void ABasePickup::HandleOverlap_Implementation(AActor* OtherActor, FHitResult SweepResult)
{

}

void ABasePickup::HandlePostPickup_Implementation()
{
	Destroy();
}

void ABasePickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CanPickup(OtherActor))
	{
		UE_LOG(Game, Log, TEXT("Collided with item"));
		HandleOverlap_Implementation(OtherActor, SweepResult);
		HandlePostPickup_Implementation();
	}
}

// Called every frame
void ABasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}