// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
<<<<<<< HEAD

=======

>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
#include "GameFramework/Pawn.h"
#include "BaseTankCharacter.h"
#include "MainCameraPawn.generated.h"

UCLASS()
class TANKSHOOTING_API AMainCameraPawn : public APawn
{
	GENERATED_BODY()

public:
<<<<<<< HEAD

=======
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
	// Sets default values for this pawn's properties
	AMainCameraPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
<<<<<<< HEAD
	static AMainCameraPawn* GetInstance();
	
	static void DestroyInstance();
	
	// Input function
	void ChangeTarget(ABaseTankCharacter* NewTarget);
	
<<<<<<< HEAD
public:
=======
protected:
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
=======
protected:
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
	
	UPROPERTY(EditAnywhere)
	USpringArmComponent* CameraSpringArm;
	
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	ABaseTankCharacter* Target;
	
<<<<<<< HEAD
<<<<<<< HEAD
	UPROPERTY(EditAnywhere)
	FVector Offset;
	
=======
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
=======
	// Input function
	void ChangeTarget();
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
	
};
