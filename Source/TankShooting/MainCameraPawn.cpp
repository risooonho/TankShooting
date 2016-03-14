// Fill out your copyright notice in the Description page of Project Settings.

#include "TankShooting.h"
#include "MainCameraPawn.h"

// Sets default values
AMainCameraPawn::AMainCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->AttachTo(RootComponent);
	CameraSpringArm->SetRelativeLocationAndRotation(
		FVector(0.0f, 0.0f, 1000.0f),
		FRotator(-30.0f, 45.0f, 0.0f));
	CameraSpringArm->TargetArmLength = 400.0f;
	CameraSpringArm->bEnableCameraLag = true;
	CameraSpringArm->CameraLagSpeed = 3.0f;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	Camera->AttachTo(CameraSpringArm, USpringArmComponent::SocketName);
	
	// Take control of the default player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	// Set Offset value
	Offset.Set(-1500, -1500, 400);
}

// Called when the game starts or when spawned
void AMainCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCameraPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// Maintain distance to target
	if (Target != nullptr)
	{
		FVector TargetLocation = Target->GetActorLocation() + Offset;
		SetActorLocation(TargetLocation, true);
	}
	
}

// Called to bind functionality to input
void AMainCameraPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AMainCameraPawn::ChangeTarget(ABaseTankCharacter* NewTarget)
{
	UE_LOG(LogClass, Log, TEXT("We got new target: %s"), *NewTarget->GetName());
<<<<<<< HEAD
	Target = NewTarget;
=======
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
}
