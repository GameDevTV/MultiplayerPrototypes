// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>("TriggerVolume");
	if (!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

