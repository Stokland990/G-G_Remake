// Fill out your copyright notice in the Description page of Project Settings.

#include "Coins.h"


// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(FName("Collision Box"));
	SetRootComponent(CollisionBox);
	CollisionBox->SetNotifyRigidBodyCollision(true);
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);

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
	CollisionBox->OnComponentHit.AddDynamic(this, &ACoins::OnHit);
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoins::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	Coin->DestroyComponent();
	CollectEffect->Activate();
	CollisionBox->DestroyComponent();
}