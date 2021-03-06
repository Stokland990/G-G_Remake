// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Classes/GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class LETSTRYTHAT_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:

	void LaunchProjectile(float Speed);

private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();

	UPROPERTY(VisibleAnywhere, Category = Components)
		UStaticMeshComponent* CollisionMesh = nullptr;


	UPROPERTY(EditDefaultsOnly, Category = SetUp)
		float ProjectileDamage = 20;

	UPROPERTY(EditDefaultsOnly, Category = SetUp)
		float DestroyDelay = 10;

	
};
