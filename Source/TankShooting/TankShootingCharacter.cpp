// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TankShooting.h"
#include "TankShootingCharacter.h"

ATankShootingCharacter::ATankShootingCharacter()
{
	// Set size for player capsule
	//GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);	
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	
	static FName CollisionProfileName(TEXT("Pawn"));
	BoxComponent->SetCollisionProfileName(CollisionProfileName);
	BoxComponent->CanCharacterStepUpOn = ECB_No;
	BoxComponent->bShouldUpdatePhysicsVolume = true;
	BoxComponent->bCheckAsyncSceneOnMove = false;
	BoxComponent->bCanEverAffectNavigation = false;
	BoxComponent->bDynamicObstacle = true;
	//BoxComponent->SetSimulatePhysics(true);
	RootComponent = BoxComponent;

/*
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
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
