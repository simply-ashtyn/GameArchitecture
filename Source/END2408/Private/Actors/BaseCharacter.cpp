// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Actors/Rifle.h"
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
	GunSocket->SetupAttachment(GetMesh(), "WeaponSocket");
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay() {
	Super::BeginPlay();
	GunSocket->SetChildActorClass(gunClass);
	childActor = GunSocket->GetChildActor();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

