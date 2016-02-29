// Fill out your copyright notice in the Description page of Project Settings.

#include "TankShooting.h"
#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "BaseTankCharacter.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create the Box Component to represent the spawn volume
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;
	
	// Initialize the tank instance to spawn
	static ConstructorHelpers::FClassFinder<ABaseTankCharacter> BlueprintLightTank(TEXT("/Game/Blueprints/LightTankCharacter"));
	if (BlueprintLightTank.Class != NULL)
	{
		LightTankCharacter = BlueprintLightTank.Class;
	}
	
	static ConstructorHelpers::FClassFinder<ABaseTankCharacter> BlueprintMediumTank(TEXT("/Game/Blueprints/MediumTankCharacter"));
	if (BlueprintMediumTank.Class != NULL)
	{
		MediumTankCharacter = BlueprintMediumTank.Class;
	}
	
	static ConstructorHelpers::FClassFinder<ABaseTankCharacter> BlueprintHeavyTank(TEXT("/Game/Blueprints/HeavyTankCharacter"));
	if (BlueprintHeavyTank.Class != NULL)
	{
		HeavyTankCharacter = BlueprintHeavyTank.Class;
	}
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnTank(LightTankCharacter);
	SpawnTank(MediumTankCharacter);
	SpawnTank(HeavyTankCharacter);
}

// Called every frame
void ASpawnVolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;
	
	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void ASpawnVolume::SpawnTank(TSubclassOf<class ABaseTankCharacter> WhatToSpawn)
{
	// If we have something to spawn
	if (WhatToSpawn != NULL)
	{
		// Check for a valid world
		UWorld* const World = GetWorld();
		if (World)
		{
			// Set the spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			
			// Get a random location to spawn at
			FVector SpawnLocation = GetRandomPointInVolume();
			if (WhatToSpawn == LightTankCharacter)
			{
				SpawnLocation.Z = 25.0f;
			}
			else if (WhatToSpawn == MediumTankCharacter)
			{
				SpawnLocation.Z = 48.0f;
			}
			else if (WhatToSpawn == HeavyTankCharacter)
			{
				SpawnLocation.Z = 90.0f;
			}
			
			// Get a random rotation for the spawned tank
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRandRange(0.0f, 360.0f);
			SpawnRotation.Pitch = 0.0f;
			SpawnRotation.Roll = 0.0f;
			
			// Spawn the tank
			ABaseTankCharacter* const SpawnedTank = World->SpawnActor<ABaseTankCharacter>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
		}
	}
}
