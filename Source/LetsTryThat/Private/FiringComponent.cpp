// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/FiringComponent.h"
#include "Public/Projectile.h"
#include "Public/FiringSpot.h"
#include "Classes/Engine/World.h"
//#include "GhostAndGoblinsCharacter.h"

// Sets default values for this component's properties
UFiringComponent::UFiringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFiringComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFiringComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFiringComponent::Fire()
{
	if (!ensure(FiringSpot)) { return; }
	if (!ensure(ProjectileBlueprint)) { return; }
	auto Projectile = GetWorld()->SpawnActor<AProjectile>
		(
			ProjectileBlueprint,
			FiringSpot->GetSocketLocation(FName("Firing")),
			FiringSpot->GetSocketRotation(FName("Firing"))
			);

	Projectile->LaunchProjectile(LaunchSpeed);
}

void UFiringComponent::Initialise(UFiringSpot* FiringSpotToSet)
{
	FiringSpot = FiringSpotToSet;
}
