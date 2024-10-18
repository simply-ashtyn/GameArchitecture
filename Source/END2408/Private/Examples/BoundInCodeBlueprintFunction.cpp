// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/BoundInCodeBlueprintFunction.h"
#include "../END2408.h"

// Add default functionality here for any IBoundInCodeBlueprintFunction functions that are not pure virtual.

void IBoundInCodeBlueprintFunction::BlueprintNativeEvent_Implementation()
{
	UE_LOG(Game, Log, TEXT("In C++ BlueprintNativeEvent_Implementation"));
}
