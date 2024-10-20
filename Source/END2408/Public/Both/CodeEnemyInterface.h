// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CodeEnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, NotBlueprintable)
class UCodeEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class END2408_API ICodeEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
	virtual void EnemyAttack() = 0;
	//virtual void EnemyAttack_Implement() = 0;
	UFUNCTION(BlueprintCallable)
	virtual void EnemyReload() = 0;
	//virtual void EnemyReload_Implement() = 0;
};
