// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
<<<<<<< HEAD
#include "MainCameraPawn.h"
=======
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
#include "TankShootingPlayerController.generated.h"

UCLASS()
class ATankShootingPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATankShootingPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
<<<<<<< HEAD
	
public:
	
	UPROPERTY(EditAnywhere)
	AMainCameraPawn* Camera;
<<<<<<< HEAD
	
private:
	
	void SetupCameraPawn();
=======
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
};
=======
};


>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
