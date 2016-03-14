// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TankShooting.h"
#include "TankShootingCharacter.h"

ATankShootingCharacter::ATankShootingCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create a Box Component
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
<<<<<<< HEAD
=======
	
/*	static FName CollisionProfileName(TEXT("Pawn"));
	BoxComponent->SetCollisionProfileName(CollisionProfileName);
	BoxComponent->CanCharacterStepUpOn = ECB_No;
	BoxComponent->bShouldUpdatePhysicsVolume = true;
	BoxComponent->bCheckAsyncSceneOnMove = false;
	BoxComponent->bCanEverAffectNavigation = false;
	BoxComponent->bDynamicObstacle = true;*/
	//BoxComponent->SetSimulatePhysics(true);
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
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
