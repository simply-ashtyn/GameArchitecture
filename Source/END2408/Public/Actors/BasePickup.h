// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

UCLASS()
class END2408_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly)
	class UBoxComponent* CollisionBox;

	UFUNCTION(BlueprintPure, BlueprintCallable)
	virtual bool CanPickup(AActor* OtherActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HandleOverlap(AActor* OtherActor, FHitResult SweepResult);
	virtual void HandleOverlap_Implementation(AActor* OtherActor, FHitResult SweepResult);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HandlePostPickup();
	virtual void HandlePostPickup_Implementation();

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
