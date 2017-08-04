// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlerGameInstance.h"


UPuzzlerGameInstance::UPuzzlerGameInstance()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance constructed."));
}

void UPuzzlerGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("GameInstance init."));

}