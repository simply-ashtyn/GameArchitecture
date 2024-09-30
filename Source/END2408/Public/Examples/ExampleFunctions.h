// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExampleFunctions.generated.h"

UCLASS()
class END2408_API AExampleFunctions : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExampleFunctions();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// This one lets you call the function from blueprint
	UFUNCTION(BlueprintCallable)
	void BlueprintCallable();

	// BlueprintImplementableEvent - declare in C++ define in blueprint
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BlueprintImplementableEvent();

	// BlueprintNativeEvent - declare in C++ define in blueprint and C++ but C++ adds _Implementation
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BlueprintNativeEvent();
	virtual void BlueprintNativeEvent_Implementation(); // override in C++

	// Pure Function
	UFUNCTION(BlueprintCallable)
	float PureFunction() const;

	// Multiple Returns
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool MultipleReturns(AActor* Actor1, FRotator Rotation, AActor *& Actor2, int32 &Index);
};
