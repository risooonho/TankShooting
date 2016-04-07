// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankShootingCharacter.h"
#include "BaseTankCharacter.generated.h"

UENUM(BlueprintType)
enum class ETankTypeEnum : uint8
{
	LIGHT,
	MEDIUM,
	HEAVY,
	SPG
};

/**
 * Base Tank Character: defines the behavior of every tank in the scene
 * The attributes of specific tank types will be define in this class' derived classes
 */
UCLASS(ABSTRACT)
class TANKSHOOTING_API ABaseTankCharacter : public ATankShootingCharacter
{
	GENERATED_BODY()
	
public:
	
	// Sets default values for this character's properties
	ABaseTankCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
public:
	
	// Side of the tank
	UPROPERTY(EditAnywhere, Category="Side")
	int32 Side;
	
	// Type of the tank: light tank, medium tank, heavy tank or SPG
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tank information")
	ETankTypeEnum TypeOfTank;
	
	// Tank's health point
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tank information")
	int32 HP;
	
	// View range: how far the tank can view
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tank information")
	float ViewRange;
	
	// Attack range: how far the tank can attack
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tank information")
	float AttackRange;
	
	// Damage: how much can the tank hurt the enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tank information")
	int32 Damage;
	
	// Rate of fire: how fast a tank can fire
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tank information")
	int32 RateOfFire;
	
	// How fast the tank can move
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tank information")
	float MoveSpeed;
	
	// How accurate the tank's shots
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tank information")
	float Accuracy;
	
public:
	
	// Spotted targets: the enemy's tanks those are currently staying in this tank and its teammates' view range
	TArray<FTransform*> *SpottedTargets;
	
	// Attackable targets: the enemy's tanks those are currently staying in this tank's attack range
	TArray<FTransform*> *AttackableTargets;
	
	// Attack target: the enemy that is staying closest to this tank and inside this tank's attack range
	FTransform* Target;
	
	/*
	 * Called to update this tank's spotted targets
	 * no @param
	 */
	void UpdateSpottedTargets();
	
	/*
	 * Called to update this tank's attackable targets
	 * no @param
	 */
	void UpdateAttackableTargets();
	
	/*
	 * Choose the closest enemy from the attackable targets
	 * no @param
	 */
	void AcquireTarget();
	
};
