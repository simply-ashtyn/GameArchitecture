// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleFunctions.h"
#include "../END2408.h"

// Sets default values
AExampleFunctions::AExampleFunctions() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void AExampleFunctions::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(Game, Error, TEXT("In Begin Play"));
	BlueprintNativeEvent(); // calls all children
	UE_LOG(Game, Error, TEXT("In Begin Play called BlueprintNativeEvent"));
	BlueprintNativeEvent_Implementation(); // calls the C++ only
	UE_LOG(Game, Error, TEXT("In Begin Play called BlueprintNativeEvent_Implementation()"));
}
// Called every frame
void AExampleFunctions::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
void AExampleFunctions::BlueprintCallable() {
	UE_LOG(Game, Log, TEXT("In C++ BlueprintCallable"));
}
void AExampleFunctions::BlueprintNativeEvent_Implementation() {
	UE_LOG(Game, Warning, TEXT("In C++ BlueprintNativeEvent_Implementation"));
}
float AExampleFunctions::PureFunction() const {
	return 3.14f;
}
//void AExampleFunctions::BlueprintImplementableEvent() {
//	UE_LOG(Game, Log, TEXT("In C++ BlueprintImplementableEvent"));
//}

