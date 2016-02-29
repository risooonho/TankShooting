// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class TANKSHOOTING_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Return the WhereToSpawn subobject
	FORCEINLINE UBoxComponent* GetWhereToSpawn() const;
	
	// Find a random point within the BoxComponent
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

public:
	
	// BoxComponent to specify where tanks should by spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;
	
	// The tank to spawn
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class ABaseTankCharacter> LightTankCharacter;
	
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class ABaseTankCharacter> MediumTankCharacter;
	
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class ABaseTankCharacter> HeavyTankCharacter;
	
private:

	// Handle spawning a new tank
	void SpawnTank(TSubclassOf<class ABaseTankCharacter> WhatToSpawn);
	
};

// ----------------- INLINES -----------------------------
FORCEINLINE UBoxComponent* ASpawnVolume::GetWhereToSpawn() const
{
	return WhereToSpawn;
}
