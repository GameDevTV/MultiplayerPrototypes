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
}

void UPuzzlerGameInstance::LoadMainMenu()
{
	if (!ensure(MenuClass != nullptr)) return;

	auto Menu = CreateWidget<UUserWidget>(this, MenuClass);
	if (!ensure(Menu != nullptr)) return;

	Menu->AddToViewport();
	
	// Step 0 get player controller.
	auto PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// Step 2 intellisense which mode options there are.
	FInputModeUIOnly InputModeData;
	// Step 3 which configure options:
	InputModeData.SetLockMouseToViewport(false);
	InputModeData.SetWidgetToFocus(Menu->TakeWidget()); //Because UMG wraps Slate
	// Step 1 what to give input mode:
	PlayerController->SetInputMode(InputModeData);

	// Step 4 enable cursor:
	PlayerController->bShowMouseCursor = true;
}

void UPuzzlerGameInstance::HostServer()
{
	// Note: the listen is important.
	GetWorld()->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}
