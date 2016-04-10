// Fill out your copyright notice in the Description page of Project Settings.

#include "TankShooting.h"
#include "EngineUtils.h"
#include "BaseTankCharacter.h"

// Sets default values
ABaseTankCharacter::ABaseTankCharacter()
	: ATankShootingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Tags.Add(FName(TEXT("Tank")));
	
	//GetMesh()->SetSimulatePhysics(true);
	//GetCapsuleComponent()->SetSimulatePhysics(true);
	
	FString DebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("Tank %s has been spawned"), *DebugString);
}

// Called when the game starts or when spawned
void ABaseTankCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Clear the spotted and attackable targets arrays
	Target = nullptr;
}

// Called every frame
void ABaseTankCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	UpdateSpottedTargets();
	UpdateAttackableTargets();
	AcquireTarget();
}

// Implement UpdateSpottedTarget
void ABaseTankCharacter::UpdateSpottedTargets()
{
	SpottedTargets.Empty();
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		for (TActorIterator<ABaseTankCharacter> TankItr(World); TankItr; ++TankItr)
		{
			ABaseTankCharacter *Tank = *TankItr;

			if (Tank == nullptr)
				continue;

			// Teammates
			if (Tank->Side == this->Side)
				continue;

			float DistanceToEnemy = FVector::Dist(this->GetActorLocation(), Tank->GetActorLocation());
			if (DistanceToEnemy <= ViewRange)
				SpottedTargets.Add(Tank);
		}
	}
}

// Implement UpdateAttackableTarget
void ABaseTankCharacter::UpdateAttackableTargets()
{
	AttackableTargets.Empty();
	for (int32 i = 0; i < SpottedTargets.Num(); i++)
	{
		float DistanceToEnemy = FVector::Dist(this->GetActorLocation(), SpottedTargets[i]->GetActorLocation());
		if (DistanceToEnemy < AttackRange)
			AttackableTargets.Add(SpottedTargets[i]);
	}
}

// Implement AcquireTarget
void ABaseTankCharacter::AcquireTarget()
{
	if (AttackableTargets.Num() == 0)
	{
		Target = nullptr;
		return;
	}

	if (Target != nullptr)
	{
		return;
	}

	float MinDistance = FVector::Dist(this->GetActorLocation(), AttackableTargets[0]->GetActorLocation());
	Target = AttackableTargets[0];
	for (int32 i = 1; i < AttackableTargets.Num(); i++)
	{
		float Distance = FVector::Dist(this->GetActorLocation(), AttackableTargets[i]->GetActorLocation());
		if (Distance < MinDistance)
		{
			MinDistance = Distance;
			Target = AttackableTargets[i];
		}
	}
}
