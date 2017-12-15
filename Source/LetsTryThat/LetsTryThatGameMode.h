// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LetsTryThatGameMode.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class ALetsTryThatGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALetsTryThatGameMode();
	
	/*virtual void Tick(float DeltaSeconds) override;

	float PresentTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = Timer)
		float AllowedTime = 5;

	UFUNCTION(BlueprintCallable, Category = Timer)
		float GetTimeLeft() const;

		*/
};



