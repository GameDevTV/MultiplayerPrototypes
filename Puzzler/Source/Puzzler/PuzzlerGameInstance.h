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

private:
	UPROPERTY()
	UClass *MenuClass;
	
};
