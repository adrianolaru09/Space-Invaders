// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Alien.h"
//#include "Bullet.h"
//#include "GameFramework/Character.h"
#include "PaperSprite.h"
//#include "PlayerWeapon.h"
//#include "Missilebase.h" 
#include "UObject/ConstructorHelpers.h"
#include "PaperSpriteComponent.h"
#include "AlienBOSS.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API AAlienBOSS : public AAlien
{
	GENERATED_BODY()
public:
	AAlienBOSS();
	UPaperSpriteComponent* bossSprite; // sprite for boss alien
	 int aliensLeft;
	 UFUNCTION()
		 void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
			 UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
			
	 UPROPERTY(VisibleAnywhere)
		 UStaticMeshComponent* bossMesh; //mesh for boss alien
protected:
	//called when the game starts or when spawned
	virtual void BeginPlay() override;
};
