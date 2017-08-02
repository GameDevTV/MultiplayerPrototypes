// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true); // Note the error if called on the server.
		SetReplicateMovement(true); // Note we don't get movement replication by default.
	}

	CurrentStartPoint = GetActorLocation();
	CurrentEndPoint = GetTransform().TransformPosition(EndPoint);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (ActiveSwitches < 1) return;

	//if (!HasAuthority()) // Challenge: try on client, note how it doesn't replicate to the server.
	if(HasAuthority())
	{
		FVector Location = GetActorLocation();
		FVector CurrentLocationToEndPoint = CurrentEndPoint - Location;
		float DistanceRemaining = FVector::DotProduct(CurrentLocationToEndPoint, GetDirection());
		if (DistanceRemaining < 0) {
			auto ToSwap = CurrentEndPoint;
			CurrentEndPoint = CurrentStartPoint;
			CurrentStartPoint = ToSwap;
		}

		Location += GetDirection() * Speed * DeltaTime;
		SetActorLocation(Location);
	}
}

void AMovingPlatform::AddActiveSwitch()
{
	ActiveSwitches++;
}

void AMovingPlatform::RemoveActiveSwitch()
{
	ActiveSwitches--;
	if (ActiveSwitches < 0) {
		ActiveSwitches = 0;
	}
}


FVector AMovingPlatform::GetDirection()
{
	return (CurrentEndPoint - CurrentStartPoint).GetSafeNormal();
}