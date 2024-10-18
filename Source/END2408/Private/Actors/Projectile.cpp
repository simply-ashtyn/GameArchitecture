// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../END2408.h"
#include "UObject/ConstructorHelpers.h" // For bad habit

// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BulletMovement"));

	BulletSphere = CreateDefaultSubobject<USphereComponent>("BulletSphere");
	SetRootComponent(BulletSphere);

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("SphereMesh");
	//attatch mesh to parent collision sphere
	SphereMesh->SetupAttachment(GetRootComponent());
	SphereMesh->SetCollisionProfileName("NoCollision");

	// DO NOT DO THIS BAD HABIT
	// POOR
	// EXAMPLE ONLY
	///Setting mesh in blueprint does not spawn

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	SphereMesh->SetStaticMesh(Asset.Object);

	// End Poor Example

	///Damage
	//BulletSphere->OnComponentHit.AddDynamic(this, &AProjectile::HandleHit);
	SphereMesh->SetGenerateOverlapEvents(true);
	BulletSphere->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::DoDamage);

	projectileMovement->InitialSpeed = 1900.f;
	projectileMovement->MaxSpeed = 1900.f;
	bulletSize = { 0.2f,0.2f,0.2f };
	timeBeforeDestroy = 3.f;
	damage = 1.f;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	//FTimerHandle DestroyTimerHandle;
	GetRootComponent()->SetWorldScale3D(bulletSize);
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AProjectile::K2_DestroyActor, 3.f);
}

void AProjectile::DoDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtherActor->TakeDamage(damage, DamageEvent, GetInstigatorController(), this);
	UE_LOG(Game, Error, TEXT("Bullet Hit"));
	Destroy();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//This will never get called
void AProjectile::HandleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	UE_LOG(Game, Log, TEXT("Hello"));
}