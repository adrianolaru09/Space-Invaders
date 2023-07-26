// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "SpriteAlien.h"
#include "AlienBOSS.h"
#include "Components/StaticMeshComponent.h"
#include "Bullet.generated.h"


UCLASS()
class SPACEINVADERS_API ABullet : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* projectileMesh;
	//projectile movement component
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* projectileMovement;

public:
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	 void virtual FireInDirection(const FVector& ShootDirection);
	
public:	
	// Sets default values for this actor's properties
	ABullet();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void DealDamage(AActor* victim);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
