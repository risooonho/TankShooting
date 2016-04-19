// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TankShooting.h"
#include "TankShootingGameMode.h"
#include "TankShootingGameState.h"
#include "TankShootingPlayerController.h"
#include "TankShootingCharacter.h"

ATankShootingGameMode::ATankShootingGameMode()
{
	PlayerControllerClass = ATankShootingPlayerController::StaticClass();
	GameStateClass = ATankShootingGameState::StaticClass();
}

void ATankShootingGameMode::InitGameState()
{
	Super::InitGameState();

	ATankShootingGameState* MyGameState = Cast<ATankShootingGameState>(GameState);
	if (MyGameState)
	{
		MyGameState->SetPlayerInControl(0);
	}
}

//ATankShootingGameMode::Tick(float DeltaSeconds)
//{
//}