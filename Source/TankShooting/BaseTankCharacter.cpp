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
	//SpottedTargets = new std::vector<FTransform*>();
	//AttackableTargets = new std::vector<FTransform*>();
	Target = NULL;
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
	//FVector::Dist()
	for (TActorIterator<AActor> It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (Actor->ActorHasTag(FName(TEXT("Tank"))))
		{
		}
	}
}

// Implement UpdateAttackableTarget
void ABaseTankCharacter::UpdateAttackableTargets()
{
}

// Implement AcquireTarget
void ABaseTankCharacter::AcquireTarget()
{
}
