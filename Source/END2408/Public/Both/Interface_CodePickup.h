// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_CodePickup.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, NotBlueprintable)
class UInterface_CodePickup : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class END2408_API IInterface_CodePickup
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
	virtual bool CanPickupHealth() = 0;
};
