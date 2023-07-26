// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alien.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "SpriteAlien.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API ASpriteAlien : public AAlien
{
	GENERATED_BODY()
	
public:
	 UPaperSpriteComponent* alienSprite;
	ASpriteAlien();
	void ChangeColor();
	void ChangeColorGreen();
	void ChangeColorBlue();
	int hitTimes = 0; // hit times counter
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
protected:
	//called when the game starts or when spawned
	virtual void BeginPlay() override;

};
