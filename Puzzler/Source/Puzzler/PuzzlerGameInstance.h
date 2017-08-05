// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLER_API UPuzzlerGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	
public:
	UPuzzlerGameInstance();

	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void LoadMainMenu();

	void LoadJoinServerMenu();

	void JoinServer(FString Address);

	void HostServer();

private:
	UPROPERTY()
	TSubclassOf<class UUserWidget> MenuClass;
	UPROPERTY()
	TSubclassOf<class UUserWidget> JoinMenuClass;

	class UUserWidget* CurrentlyActiveMenu;

	void ShowMenu();
	void HideMenu();
	
};
