// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWeapon.h"

// Sets default values for this component's properties
UPlayerWeapon::UPlayerWeapon()
{
	//weapon sprite
	weaponSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("weaponSprite"));
	weaponSprite->AttachTo(this);
	weaponSprite->SetSprite(ConstructorHelpers::FObjectFinder<UPaperSprite>(TEXT("/Game/Images/mbase_Sprite1.mbase_Sprite1")).Object);
	weaponSprite->SetSpriteColor(FLinearColor(1.0f, 0.f, 0.f));
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

// Called when the game starts
void UPlayerWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UPlayerWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
void UPlayerWeapon::ShootOne()
{
	const FRotator FireRotation = FRotator(0.f, 0.f, 0.f); // rotation
	UWorld* const World = GetWorld(); // world reference
	if (World != NULL)
	{
		// spawn the projectile
		ABullet* thisBullet = World->SpawnActor<ABullet>(GetOwner()->GetActorLocation() + FVector(5.f, 0.f, 20.f), FireRotation);
		thisBullet->FireInDirection(FVector(0.f, 0.f, 1.f));
		thisBullet->SetOwner(GetOwner());
		if (GEngine)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, FString::Printf(TEXT(" bullet nr1")));
		}
	}
}

void UPlayerWeapon::ShootTriple()
{
	const FRotator FireRotation = FRotator(0.f, 0.f, 0.f);
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		float i =-1;
			for (i; i < 2; i++) // loop for 3 bullets
			{
				//spawn explosive bullet 
				float offsetX = i * 40.f; // distance between the bullets so they don't collide with eachother
				AExplosiveBullet* exBullet = World->SpawnActor<AExplosiveBullet>(GetOwner()->GetActorLocation() + FVector(offsetX , 0.f, 20.f), FireRotation);
				exBullet->FireInDirection(FVector(i, 0.f, 1.f));
				exBullet->SetOwner(GetOwner());
				if (GEngine)
				{
					//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, FString::Printf(TEXT("explosive bullet nr2 '%d'"),i));
				}
			}
	}
}

