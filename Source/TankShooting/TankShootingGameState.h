// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "TankShootingGameState.generated.h"

/**
 * 
 */
UCLASS()
class TANKSHOOTING_API ATankShootingGameState : public AGameState
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turn")
	int32 PlayerInControl;

	UFUNCTION(BlueprintCallable, Category = "Turn")
	int32 GetPlayerInControl();

	UFUNCTION(BlueprintCallable, Category = "Turn")
	void SetPlayerInControl(int32 NewPlayer);
	
};
