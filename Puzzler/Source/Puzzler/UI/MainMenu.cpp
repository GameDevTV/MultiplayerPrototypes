// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"


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
	UE_LOG(LogTemp, Warning, TEXT("Host Server!"));
}