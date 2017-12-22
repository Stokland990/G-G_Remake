// Fill out your copyright notice in the Description page of Project Settings.

#include "Coins.h"
#include"Classes/GameFramework/Actor.h"

// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(FName("Collision Box"));
	SetRootComponent(CollisionBox);

	Coin = CreateDefaultSubobject<UParticleSystemComponent>(FName("Coin to collect"));
	Coin->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	CollectEffect = CreateDefaultSubobject<UParticleSystemComponent>(FName("Coin collect effect"));
	CollectEffect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CollectEffect->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACoins::OnOverlapBegin);
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoins::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Coin->DestroyComponent();
	CollectEffect->Activate();
	CollisionBox->DestroyComponent();
	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ACoins::OnTimerExpire, DestroyDelay, false);
}

void ACoins::OnTimerExpire()
{
	Destroy();
}
