// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "BaseTankCharacter.h"
#include "MainCameraPawn.generated.h"

UCLASS()
class TANKSHOOTING_API AMainCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainCameraPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
protected:
	
	UPROPERTY(EditAnywhere)
	USpringArmComponent* CameraSpringArm;
	
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	ABaseTankCharacter* Target;
	
	// Input function
	void ChangeTarget();
	
};
