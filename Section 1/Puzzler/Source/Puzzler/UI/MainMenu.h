// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLER_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinServerButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* HostServerButton;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ErrorMessage;

	UFUNCTION()
	void JoinServerPressed();

	UFUNCTION()
	void HostServerPressed();
};
