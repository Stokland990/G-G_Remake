// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "LetsTryThatGameMode.h"
#include "LetsTryThatCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Classes/Engine/World.h"

ALetsTryThatGameMode::ALetsTryThatGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Player/SideScrollerBP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

/*
void ALetsTryThatGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	float GameOverTime = 0;
	PresentTime = AllowedTime - (GetWorld()->GetTimeSeconds());
	GetTimeLeft();
	if (PresentTime <= GameOverTime)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameOver!"))
	}
}

float ALetsTryThatGameMode::GetTimeLeft() const 
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), PresentTime)
	return PresentTime;
}
*/