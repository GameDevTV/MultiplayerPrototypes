// Fill out your copyright notice in the Description page of Project Settings.

#include "JoinServerMenu.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"

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
	UE_LOG(LogTemp, Warning, TEXT("Server IP entered: %s"), *IpAddress);
}
