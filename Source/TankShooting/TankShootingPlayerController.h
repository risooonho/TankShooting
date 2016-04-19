// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "MainCameraPawn.h"
#include "TankShootingGameState.h"
#include "BaseTankCharacter.h"
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
	
public:
	
	UPROPERTY(EditAnywhere)
	AMainCameraPawn* Camera;
	
private:
	
	void PossessTank(ABaseTankCharacter* Tank);

	void SetupCameraPawn();

	bool IsAtTarget();

	ATankShootingGameState* MyGameState;

	ABaseTankCharacter* CurrentTankInControl;

	FVector* GoalLoc;

	bool bTargetSelected;
};
