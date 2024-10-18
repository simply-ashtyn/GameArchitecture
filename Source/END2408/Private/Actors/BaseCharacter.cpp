// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ChildActorComponent.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	GetMesh()->SetRelativeLocation(FVector{ 0.f,0.f,-90.f });
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));	
	GetMesh()->SetGenerateOverlapEvents(true);

	GunSocket = CreateDefaultSubobject<UChildActorComponent>(TEXT("GunSocket"));
	GunSocket->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale,"PlaceWeaponHere");

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	isDead = false;
}

void ABaseCharacter::HandleHurt()
{
	Animator->PlayHurt(0);
}

void ABaseCharacter::HandleDeath()
{
	Animator->PlayDeath();
	isDead = true;
	Gun->OwnerDead();
	//UPawnMovementComponent* move = GetMovementComponent();
	//MovementComponent = CastChecked<UMovementComponent>(move);
	//MovementComponent->StopMovementImmediately();

	//STOP PROJECTILES FROM COLLIDING WITH DEAD CHARACTER
	//CapsuleComponent = GetCapsuleComponent();
	//CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseCharacter::BindWeaponAndAnimations_Implementation()
{
	HealthComponent->OnHurt.AddDynamic(Animator, &UCharacterAnimation::PlayHurt);
	Gun->OnAttack.AddDynamic(Animator, &UCharacterAnimation::PlayShoot);
	Animator->OnShootEnded.AddDynamic(Gun, &ARifle::ActionEnded);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay() {
	Super::BeginPlay();
	childActor = GunSocket->GetChildActor();
	Gun = Cast<ARifle>(childActor);
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	Animator = CastChecked<UCharacterAnimation>(AnimInstance);
	HealthComponent->OnDeath.AddDynamic(this, &ABaseCharacter::HandleDeath);
	BindWeaponAndAnimations();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseCharacter::Shoot_Implementation()
{
	if (!isDead)
	{
		Gun->Shoot();
		Animator->PlayShoot();
	}
}

void ABaseCharacter::Reload_Implementation()
{
	if (Gun->RequestReload())
	{
		Animator->PlayReload();
	}
}

bool ABaseCharacter::CanPickupHealth()
{
	return false;
}