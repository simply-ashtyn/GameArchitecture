// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HealthComponent.h"
#include "GameFramework/Actor.h"
#include "Both/CharacterAnimation.h"
#include "Actors/BaseCharacter.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	maxHealth = 5.f;
	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeDamage);
	currentHealth = maxHealth;
	character = CastChecked<ABaseCharacter>(GetOwner());

	UAnimInstance* AnimInstance = character->GetMesh()->GetAnimInstance();
	Animator = CastChecked<UCharacterAnimation>(AnimInstance);
	UE_LOG(LogTemp, Warning, TEXT("on begin cur health %f"), currentHealth);
}

void UHealthComponent::HandleTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigateBy, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Pre damage cur health %f"), currentHealth);

	if (Damage == 0 || DamagedActor == DamageCauser || currentHealth == 0)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("took %f damage"), Damage);
	
	currentHealth = FMath::Clamp(currentHealth - Damage, 0.f, maxHealth);
	float percent = currentHealth / maxHealth;

	UE_LOG(LogTemp, Warning, TEXT("remaining health: %f"), currentHealth);

	if (Damage < 0)
	{
		OnHeal.Broadcast(percent);
		UE_LOG(LogTemp, Warning, TEXT("onHeal health: %f"), currentHealth);
	}
	else if (currentHealth > 0)
	{
		Animator->PlayHurt(0);
		OnHurt.Broadcast(percent);
	}

	UE_LOG(LogTemp, Warning, TEXT("remaining health: %f"), currentHealth);

	if (currentHealth <= 0)
	{
		//actor died
		OnDeath.Broadcast();
		GetOwner()->OnTakeAnyDamage.Clear();
	}
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

