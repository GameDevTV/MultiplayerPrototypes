// Fill out your copyright notice in the Description page of Project Settings.

#include "JoinServerMenu.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"

#include "../PuzzlerGameInstance.h"

bool UJoinServerMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UJoinServerMenu::JoinPressed);

	return true;
}

void UJoinServerMenu::JoinPressed()
{
	if (!ensure(ServerIPField != nullptr)) return;

	FString IpAddress = ServerIPField->Text.ToString();

	auto World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto GameInstance = Cast<UPuzzlerGameInstance>(World->GetGameInstance());

	GameInstance->JoinServer(IpAddress);
}
