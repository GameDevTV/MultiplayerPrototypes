// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlerGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

UPuzzlerGameInstance::UPuzzlerGameInstance()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuClassFinder(TEXT("/Game/UI/WBP_MainMenu")); //Must be in constructor.
	MenuClass = MenuClassFinder.Class;
}

void UPuzzlerGameInstance::Init()
{
	Super::Init();
	if (!ensure(MenuClass != nullptr)) return;
	UE_LOG(LogTemp, Warning, TEXT("GameInstance has menu class %s"), *MenuClass->GetFName().ToString());
}