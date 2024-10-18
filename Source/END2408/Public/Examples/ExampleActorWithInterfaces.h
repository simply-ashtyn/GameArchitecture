// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Examples/BoundInCodeBlueprintFunction.h"
#include "ExampleActorWithInterfaces.generated.h"

UCLASS()
class END2408_API AExampleActorWithInterfaces : public AActor, public IBoundInCodeBlueprintFunction

{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExampleActorWithInterfaces();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//-------------------------------//
	// IBoundInCodeBlueprintFunction
	//-------------------------------//
	 
	virtual void BlueprintNativeEvent_Implementation() override;
	 
	//-------------------------------//
	// IBoundInCodeBlueprintFunction
	//-------------------------------//

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
