// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TankShooting.h"
<<<<<<< HEAD
#include "BaseTankCharacter.h"
#include "EngineUtils.h"
=======
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
#include "TankShootingPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"

ATankShootingPlayerController::ATankShootingPlayerController()
{
	bShowMouseCursor = true;
<<<<<<< HEAD
<<<<<<< HEAD
	DefaultMouseCursor = EMouseCursor::Default;
	
	SetupCameraPawn();
}

void ATankShootingPlayerController::SetupCameraPawn()
{
=======
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		for (TActorIterator<AMainCameraPawn> ActorItr(World); ActorItr; ++ActorItr)
		{
			AMainCameraPawn *CameraPawn = *ActorItr;
			FString CameraPawnName = CameraPawn->GetName();
			if (CameraPawnName.Contains(TEXT("MainCameraPawn")))
			{
				Camera = CameraPawn;
			}
		}
	}
=======
	DefaultMouseCursor = EMouseCursor::Crosshairs;
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
}

void ATankShootingPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void ATankShootingPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATankShootingPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ATankShootingPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATankShootingPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ATankShootingPlayerController::MoveToTouchLocation);
}

void ATankShootingPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
<<<<<<< HEAD
	
	if (Hit.GetActor() != nullptr)
<<<<<<< HEAD
=======
	{
		AActor* HitActor = Hit.GetActor();
		FString HitActorName = Hit.GetActor()->GetName();
		if (HitActorName.Contains(TEXT("Tank")))
		{
			// Process here if hits a tank
			UnPossess();
			Possess((APawn*)HitActor);
			UE_LOG(LogClass, Log, TEXT("Possess tank %s"), *HitActor->GetName());
			Camera->ChangeTarget((ABaseTankCharacter*)HitActor);
			
			SetViewTarget(Camera);
		}
		else if (HitActorName.Contains(TEXT("Floor")))
		{
			// Process here if hits floor
		}
		//UE_LOG(LogClass, Log, TEXT("Clicked to %s"), *Hit.GetActor()->GetName());
	}

	if (Hit.bBlockingHit)
>>>>>>> 193e12b... Allow PlayerController to possess tanks when clicking on one
	{
		AActor* HitActor = Hit.GetActor();
		FString HitActorName = Hit.GetActor()->GetName();
		if (HitActorName.Contains(TEXT("Tank")))
		{
			// Process here if hits a tank
			UnPossess();
			Possess((APawn*)HitActor);
			UE_LOG(LogClass, Log, TEXT("Possess tank %s"), *HitActor->GetName());
			Camera->ChangeTarget((ABaseTankCharacter*)HitActor);
			
			SetViewTarget(Camera);
		}
		else if (HitActorName.Contains(TEXT("Floor")))
		{
			// Process here if hits floor
			SetNewMoveDestination(Hit.ImpactPoint);
			UE_LOG(LogClass, Log, TEXT("%s Move to impact Point: %f, %f, %f"), *Camera->Target->GetName(), Hit.ImpactPoint.X, Hit.ImpactPoint.Y, Hit.ImpactPoint.Z);
		}
		//UE_LOG(LogClass, Log, TEXT("Clicked to %s"), *Hit.GetActor()->GetName());
	}

	//if (Hit.bBlockingHit)
	//{
	//	// We hit something, move there
	//	SetNewMoveDestination(Hit.ImpactPoint);
	//}
=======

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
}

void ATankShootingPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ATankShootingPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());
<<<<<<< HEAD
		UE_LOG(LogClass, Log, TEXT("Has pawn"));

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && Distance >= 120.0f)
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
			UE_LOG(LogClass, Log, TEXT("Has nav sys"));
=======

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
>>>>>>> 3570a75ad0f871395cde9a54c506f2fb884ac3ae
		}
	}
}

void ATankShootingPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ATankShootingPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
