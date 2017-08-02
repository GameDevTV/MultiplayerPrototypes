// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>("TriggerVolume");
	if (!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;

	TriggerVolume->bGenerateOverlapEvents = true;
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnBeginOverlap);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnEndOverlap);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlatformTrigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Activate"));
}

void APlatformTrigger::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Deactivate"));
}
