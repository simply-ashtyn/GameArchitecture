// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectile.h"
//#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "../END2408.h"// for the log file
#include "UObject/ConstructorHelpers.h" // For bad habit

// Sets default values
AProjectile::AProjectile() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BulletSphere = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SetRootComponent(BulletSphere);

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("SphereMesh");
	BulletMesh->SetCollisionProfileName("NoCollision");
	//attatch mesh to parent collision sphere
	BulletMesh->SetupAttachment(GetRootComponent());

	// 1 right-click the delegate and go to declaration
	// 2 Right-click and go to the declaration of the type
	// 3 copy from the back how many many input params
	// 4 Create a function with the same function signature
	BulletSphere->OnComponentHit.AddDynamic(this, &AProjectile::HandleHit);

	//What students normally do
	//comment out next line to compile
	//BulletSphere->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::HandleHit);

	// DO NOT DO THIS BAD HABIT
	// POOR
	// EXAMPLE ONLY

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	BulletMesh->SetStaticMesh(Asset.Object);

	// End Poor Example

	//projectileMovement->InitialSpeed = 1500.f;
	//projectileMovement->MaxSpeed = 3000.f;
	//bulletSize = { 0.1f,0.1f,0.1f };
	//timeBeforeDestroy = 3.f;
	//damage = 1.f;
}
// Called when the game starts or when spawned
void AProjectile::BeginPlay() {
	Super::BeginPlay();

	FTimerHandle DestroyTimerHandle;
	//Use 5 of 6
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AProjectile::K2_DestroyActor, 3.f);
}
//void AProjectile::DoDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//}

// Called every frame
void AProjectile::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
//This will never get called
void AProjectile::HandleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	UE_LOG(Game, Log, TEXT("Hello"));
}

