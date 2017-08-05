// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JoinServerMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLER_API UJoinServerMenu : public UUserWidget
{
	GENERATED_BODY()

	bool Initialize();

private:
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* ServerIPField;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UFUNCTION()
	void JoinPressed();
};
