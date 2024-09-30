// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleDefaultPawn.h"
#include "../END2408.h"
#include "GameFramework/PlayerInput.h"

// Sets default values
AExampleDefaultPawn::AExampleDefaultPawn() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void AExampleDefaultPawn::BeginPlay() {
	Super::BeginPlay();

	// Upcast
	AActor* Actor = this;

	// Down Cast
	APawn* Pawn = Cast<APawn>(Actor);

	if(Pawn) {
		// Valid
		UE_LOG(Game, Warning, TEXT("Actor is %s"), *Pawn->GetName());
	} else {
		// Not Valid
		UE_LOG(Game, Log, TEXT("Numbers are %d or %f"), 3, 3.14f);
	}

	UE_LOG(Game, Error, TEXT("Velocity is %s"), *GetVelocity().ToString());

	UE_LOG(Game, Log, TEXT("it is %s"), true ? TEXT("TRUE") : TEXT("FALSE"));
}
// Called every frame
void AExampleDefaultPawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
// Called to bind functionality to input
void AExampleDefaultPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// do not need to migrate the project settings to code
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TEST_SPAWN", EKeys::SpaceBar));

	PlayerInputComponent->BindAction("TEST_SPAWN", EInputEvent::IE_Pressed, this, &AExampleDefaultPawn::Spawn);
}
void AExampleDefaultPawn::Spawn() {
	FActorSpawnParameters Params;
	Params.Instigator = this;
	GetWorld()->SpawnActor<AActor>(SpawnBlueprintClass, GetActorTransform(), Params);
}

