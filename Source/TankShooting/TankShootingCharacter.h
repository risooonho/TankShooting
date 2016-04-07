// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "TankShootingCharacter.generated.h"

UCLASS(Blueprintable)
<<<<<<< HEAD
class ATankShootingCharacter : public APawn
{
	GENERATED_BODY()
<<<<<<< HEAD
=======

/*	//Top down camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	// Camera boom positioning the camera above the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom; */
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
=======
class ATankShootingCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
	
public:
	
	// Box Collision as the root component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent *BoxComponent;

<<<<<<< HEAD
	// CharacterMovement for controlling tank's movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPawnMovementComponent* PawnMovement;
=======
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae

public:
	ATankShootingCharacter();

<<<<<<< HEAD
<<<<<<< HEAD
	class UPawnMovementComponent* GetPawnMovement() const;

=======
/*	// Returns TopDownCameraComponent subobject
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	// Returns CameraBoom subobject
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }*/
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
=======
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
};

