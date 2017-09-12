// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PUZZLER_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Speed = 20;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector EndPoint;

	void AddActiveSwitch();
	void RemoveActiveSwitch();

private:
	FVector CurrentStartPoint;
	FVector CurrentEndPoint;

	FVector GetDirection();

	UPROPERTY(EditAnywhere)
	int ActiveSwitches = 1;
};
