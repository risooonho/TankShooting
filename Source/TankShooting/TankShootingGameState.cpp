// Fill out your copyright notice in the Description page of Project Settings.

#include "TankShooting.h"
#include "TankShootingGameState.h"

int32 ATankShootingGameState::GetPlayerInControl()
{
	return PlayerInControl;
}

void ATankShootingGameState::SetPlayerInControl(int32 NewPlayer)
{
	PlayerInControl = NewPlayer;
}
