// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "TankShootingGameMode.generated.h"

UCLASS(minimalapi)
class ATankShootingGameMode : public AGameMode
{
	GENERATED_BODY()

protected:

	virtual void InitGameState();

public:
	ATankShootingGameMode();

	//virtual void Tick(float DeltaSeconds) OVERRIDE;

};
