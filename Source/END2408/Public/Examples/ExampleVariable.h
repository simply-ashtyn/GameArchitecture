// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


#include "ExampleVariable.generated.h"

// Create a Delegate Class and Sets the Function Signature
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVariableDelegate, AActor*, OtherActor);


UCLASS(Abstract)
class END2408_API AExampleVariable : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExampleVariable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Not exposed to blueprint
	bool CPlusPlusOnly;

	// Exposed to blueprint Read Only
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variables|ReadOnly")
	bool VisibleAnywhere;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Variables|ReadOnly")
	uint8 VisibleDefaultsOnly;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Variables|ReadOnly")
	int32 VisibleInstanceOnlyOdd;
	UPROPERTY(VisibleInstanceOnly, Category = "Variables|ReadOnly")
	int64 VisibleInstanceOnly;

	// Exposed to blueprint Read Write
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables|ReadWrite")
	float EditAnywhere;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variables|ReadWrite")
	FName EditDefaultsOnlyOdd;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Variables|ReadWrite")
	FString EditInstanceOnlyOdd;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variables|ReadWrite")
	FName EditDefaultsOnly;
	UPROPERTY(EditInstanceOnly, Category = "Variables|ReadWrite")
	FString EditInstanceOnly;

	// Class Reference
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variables|ClassReference")
	TSubclassOf<AActor> ClassType;

	// Create a variable of the delegate type created above
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Variable)
	FVariableDelegate OnExampleDelegateVariable;

	// Arrays
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variables|Array")
	TArray<int32> ValueArray;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variables|Array")
	TArray<UObject*> PointerArray;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UFUNCTION()
	void ExampleBoundFunction(AActor* Other);
	UFUNCTION()
	void ExampleMultipleBoundFunctions(AActor* Actor);
};
