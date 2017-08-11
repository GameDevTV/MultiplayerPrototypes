// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlerGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"
#include "MoviePlayer.h"

UPuzzlerGameInstance::UPuzzlerGameInstance()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuClassFinder(TEXT("/Game/UI/WBP_MainMenu")); //Must be in constructor.
	MenuClass = MenuClassFinder.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> JoinMenuClassFinder(TEXT("/Game/UI/WBP_JoinServerMenu")); //Must be in constructor.
	JoinMenuClass = JoinMenuClassFinder.Class;
}

void UPuzzlerGameInstance::Init()
{
	Super::Init();

	auto Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->OnTravelFailure().AddUObject(this, &UPuzzlerGameInstance::HandleTravelError);
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UPuzzlerGameInstance::BeginLoadingScreen);
}

void UPuzzlerGameInstance::LoadMainMenu()
{
	if (!ensure(MenuClass != nullptr)) return;

	CurrentlyActiveMenu = CreateWidget<UUserWidget>(this, MenuClass);

	ShowMenu();

}

void UPuzzlerGameInstance::LoadJoinServerMenu()
{
	if (!ensure(JoinMenuClass != nullptr)) return;

	HideMenu();
	CurrentlyActiveMenu = CreateWidget<UUserWidget>(this, JoinMenuClass);
	ShowMenu();
}

void UPuzzlerGameInstance::JoinServer(FString Address)
{
	auto PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// Absolute means use all address.
	PlayerController->ClientTravel(Address, TRAVEL_Absolute);
	HideMenu();
}

void UPuzzlerGameInstance::HostServer()
{
	// Note: the listen is important.
	GetWorld()->ServerTravel("/Game/Maps/MainPuzzle?listen");

	HideMenu();
}

FString UPuzzlerGameInstance::GetErrorMessage()
{
	return ErrorMessage; //To test use some other string
}

void UPuzzlerGameInstance::ShowMenu()
{
	if (!ensure(CurrentlyActiveMenu != nullptr)) return;

	CurrentlyActiveMenu->AddToViewport();

	// Step 0 get player controller.
	auto PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// Step 2 intellisense which mode options there are.
	FInputModeUIOnly InputModeData;
	// Step 3 which configure options:
	InputModeData.SetLockMouseToViewport(false);
	InputModeData.SetWidgetToFocus(CurrentlyActiveMenu->TakeWidget()); //Because UMG wraps Slate
																	   // Step 1 what to give input mode:
	PlayerController->SetInputMode(InputModeData);

	// Step 4 enable cursor:
	PlayerController->bShowMouseCursor = true;
}

void UPuzzlerGameInstance::HideMenu()
{
	if (!ensure(CurrentlyActiveMenu != nullptr)) return;

	CurrentlyActiveMenu->RemoveFromViewport();

	auto PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = false;
}

void UPuzzlerGameInstance::HandleTravelError(UWorld* World, ETravelFailure::Type TravelFailure, const FString& Message)
{
	ErrorMessage = "An error occurred: " + Message;
	LoadMainMenu();
}

void UPuzzlerGameInstance::BeginLoadingScreen(const FString& MapName)
{
	UE_LOG(LogTemp, Warning, TEXT("Showing loading screen"));

	FLoadingScreenAttributes LoadingScreen;
	LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
	LoadingScreen.MinimumLoadingScreenDisplayTime = 2;
	LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();

	GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
}
