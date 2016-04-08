// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TankShooting.h"
#include "TankShootingCharacter.h"

ATankShootingCharacter::ATankShootingCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create a Box Component
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	// Create a Character Movement component
	PawnMovement = CreateDefaultSubobject<UPawnMovementComponent>(TEXT("CharacterMovement"));
	if (PawnMovement)
	{
		PawnMovement->UpdatedComponent = BoxComponent;
	}

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	//GetPawnMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	//GetPawnMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetPawnMovement()->bConstrainToPlane = true;
	GetPawnMovement()->bSnapToPlaneAtStart = true;

}

class UPawnMovementComponent* ATankShootingCharacter::GetPawnMovement() const
{
	return PawnMovement;
}
