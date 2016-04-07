// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TankShooting.h"
#include "TankShootingCharacter.h"

ATankShootingCharacter::ATankShootingCharacter()
{
<<<<<<< HEAD
	PrimaryActorTick.bCanEverTick = true;

	// Create a Box Component
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
<<<<<<< HEAD
=======
	
/*	static FName CollisionProfileName(TEXT("Pawn"));
=======
	// Set size for player capsule
	//GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);	
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	
	static FName CollisionProfileName(TEXT("Pawn"));
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
	BoxComponent->SetCollisionProfileName(CollisionProfileName);
	BoxComponent->CanCharacterStepUpOn = ECB_No;
	BoxComponent->bShouldUpdatePhysicsVolume = true;
	BoxComponent->bCheckAsyncSceneOnMove = false;
	BoxComponent->bCanEverAffectNavigation = false;
<<<<<<< HEAD
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

=======
	BoxComponent->bDynamicObstacle = true;
	//BoxComponent->SetSimulatePhysics(true);
	RootComponent = BoxComponent;

/*
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
<<<<<<< HEAD
	//GetPawnMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	//GetPawnMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetPawnMovement()->bConstrainToPlane = true;
	GetPawnMovement()->bSnapToPlaneAtStart = true;

}

class UPawnMovementComponent* ATankShootingCharacter::GetPawnMovement() const
{
	return PawnMovement;
}
=======
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	//CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->RelativeRotation = FRotator(-30.0f, 45.0f, 0.0f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	//TopDownCameraComponent->AddLocalRotation(FRotator(0, 0, 0));
*/

}
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
