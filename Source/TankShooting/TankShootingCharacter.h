// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "TankShootingCharacter.generated.h"

UCLASS(Blueprintable)
class ATankShootingCharacter : public APawn
{
	GENERATED_BODY()
	
public:
	
	// Box Collision as the root component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent *BoxComponent;

	// CharacterMovement for controlling tank's movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPawnMovementComponent* PawnMovement;

public:
	ATankShootingCharacter();

	class UPawnMovementComponent* GetPawnMovement() const;

};

