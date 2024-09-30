// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleVariable.h"
#include "../END2408.h"

// Sets default values
AExampleVariable::AExampleVariable() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	ClassType = AExampleVariable::StaticClass();

	ValueArray.Add(3);
	ValueArray.Add(4);

	PointerArray.Add(this);
	PointerArray.Add(nullptr);
}
// Called when the game starts or when spawned
void AExampleVariable::BeginPlay() {
	Super::BeginPlay();

	// This is the same thing as Bind Event in C++
	// Variavbles sent in to AddDynamic is the same thing as sent to create event
	// as seen on Base character begin play
	OnExampleDelegateVariable.AddDynamic(this, &AExampleVariable::ExampleBoundFunction);
	OnExampleDelegateVariable.AddDynamic(this, &AExampleVariable::ExampleMultipleBoundFunctions);

	// Same thing as Call in blueprint
	// As seen in Rifle:Attack
	OnExampleDelegateVariable.Broadcast(this);
}
// Called every frame
void AExampleVariable::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}
void AExampleVariable::ExampleBoundFunction(AActor* Other) {
	UE_LOG(Game, Warning, TEXT("Bound function called"));
}
void AExampleVariable::ExampleMultipleBoundFunctions(AActor* Actor) {
	UE_LOG(Game, Error, TEXT("M any Bound function called"));
}

