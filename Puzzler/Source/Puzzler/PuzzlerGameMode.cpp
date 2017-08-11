// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PuzzlerGameMode.h"
#include "PuzzlerCharacter.h"
#include "UObject/ConstructorHelpers.h"

APuzzlerGameMode::APuzzlerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
