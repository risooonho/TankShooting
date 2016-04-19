// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TankShooting.h"
#include "BaseTankCharacter.h"
#include "EngineUtils.h"
#include "TankShootingPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"

ATankShootingPlayerController::ATankShootingPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	SetupCameraPawn();

	//MyGameState = Cast<ATankShootingGameState>(GetWorld()->GameState);
	MyGameState = nullptr;
	CurrentTankInControl = nullptr;
	GoalLoc = nullptr;
	bTargetSelected = false;
}

void ATankShootingPlayerController::SetupCameraPawn()
{
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
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATankShootingPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (MyGameState == nullptr)
	{
		UWorld* World = GetWorld();
		MyGameState = Cast<ATankShootingGameState>(World->GameState);
	}

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}

	// Change turn to other player
	if (IsAtTarget())
	{
		MyGameState->SetPlayerInControl(1 - MyGameState->GetPlayerInControl());
		int32 NextSide = MyGameState->GetPlayerInControl();
		UWorld* World = GetWorld();

		UE_LOG(LogClass, Log, TEXT("Is at target"));

		if (World != nullptr)
		{
			for (TActorIterator<ABaseTankCharacter> TankItr(World); TankItr; ++TankItr)
			{
				ABaseTankCharacter *Tank = *TankItr;

				if (Tank == nullptr)
					continue;

				if (Tank->Side == NextSide)
				{
					PossessTank(Tank);
					//UE_LOG(LogClass, Log, TEXT("Possess new tank: %s"), *Tank->GetName());

					delete GoalLoc;
					GoalLoc = nullptr;
					bTargetSelected = false;

					break;
				}
			}
		}
	}
}

void ATankShootingPlayerController::PossessTank(ABaseTankCharacter *Tank)
{
	UnPossess();
	Possess(Tank);
	CurrentTankInControl = Tank;
	Camera->ChangeTarget(Tank);
	//UE_LOG(LogClass, Log, TEXT("Camera new target: %s"), *Camera->Target->GetName());
//	if (GetViewTarget() != Camera)
	SetViewTarget(Camera);
}

void ATankShootingPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATankShootingPlayerController::OnSetDestinationPressed);
	//InputComponent->BindAction("SetDestination", IE_Released, this, &ATankShootingPlayerController::OnSetDestinationReleased);
}

void ATankShootingPlayerController::MoveToMouseCursor()
{
	bMoveToMouseCursor = false;

	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	
	if (Hit.GetActor() != nullptr)
	{
		AActor* HitActor = Hit.GetActor();
		FString HitActorName = Hit.GetActor()->GetName();
		if (HitActorName.Contains(TEXT("Tank")))
		{
			// Check if we have picked move target or not
			if (bTargetSelected)
				return;

			// Check if hit a fellow tank
			ABaseTankCharacter* HitTank = (ABaseTankCharacter*)HitActor;
			if (HitTank->Side != MyGameState->GetPlayerInControl())
			{
				return;
			}

			// Process here if hits a fellow tank
			PossessTank(HitTank);
		}
		else if (HitActorName.Contains(TEXT("Floor")))
		{
			// Process here if hits floor
			if (bTargetSelected)
				return;

			SetNewMoveDestination(Hit.ImpactPoint);
			UE_LOG(LogClass, Log, TEXT("%s Move to impact Point: %f, %f, %f"), *Camera->Target->GetName(), Hit.ImpactPoint.X, Hit.ImpactPoint.Y, Hit.ImpactPoint.Z);
		}
	}
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

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && Distance >= 300.0f)
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
			GoalLoc = new FVector(DestLocation.X, DestLocation.Y, DestLocation.Z);
			bTargetSelected = true;
		}
	}
}

void ATankShootingPlayerController::OnSetDestinationPressed()
{
	if (MyGameState == nullptr)
		return;

	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ATankShootingPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

bool ATankShootingPlayerController::IsAtTarget()
{
	if (!bTargetSelected)
		return false;

	if (GoalLoc == nullptr)
		return false;

	UPathFollowingComponent* PFollowComp = nullptr;
	InitNavigationControl(PFollowComp);

	if (PFollowComp == nullptr)
	{
		return false;
	}

	if (PFollowComp->HasReached(*GoalLoc))
	{
		return true;
	}

	return false;
}
