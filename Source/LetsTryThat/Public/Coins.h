// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Classes/Components/BoxComponent.h"
#include "Classes/Particles/ParticleSystemComponent.h"
#include "Coins.generated.h"


UCLASS()
class LETSTRYTHAT_API ACoins : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoins();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, Category = Components)
		UBoxComponent* CollisionBox = nullptr;
	
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UParticleSystemComponent* Coin = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		UParticleSystemComponent* CollectEffect = nullptr;
};
