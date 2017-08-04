// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "../PuzzlerGameInstance.h"


bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(HostServer != nullptr)) return false;
	HostServer->OnClicked.AddDynamic(this, &UMainMenu::HostServerPressed);

	return true;
}

void UMainMenu::HostServerPressed()
{
	auto World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto GameInstance = Cast<UPuzzlerGameInstance>(World->GetGameInstance());

	GameInstance->HostServer();
}