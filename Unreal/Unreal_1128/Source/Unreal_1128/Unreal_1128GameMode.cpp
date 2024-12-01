// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unreal_1128GameMode.h"
#include "Unreal_1128Character.h"
#include "UObject/ConstructorHelpers.h"

AUnreal_1128GameMode::AUnreal_1128GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
