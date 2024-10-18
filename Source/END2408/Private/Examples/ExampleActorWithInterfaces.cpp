// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleActorWithInterfaces.h"
#include "../END2408.h"

// Sets default values
AExampleActorWithInterfaces::AExampleActorWithInterfaces()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExampleActorWithInterfaces::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExampleActorWithInterfaces::BlueprintNativeEvent_Implementation()
{
	IBoundInCodeBlueprintFunction::BlueprintNativeEvent_Implementation();
	UE_LOG(Game, Log, TEXT("In C++ class BlueprintNativeEvent_Implementation override"));
}

// Called every frame
void AExampleActorWithInterfaces::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

