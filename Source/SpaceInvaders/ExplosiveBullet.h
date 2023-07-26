// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "ExplosiveBullet.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API AExplosiveBullet : public ABullet
{
	GENERATED_BODY()
public:
		AExplosiveBullet();
	    
protected:
	//called when the game starts or when spawned
	virtual void BeginPlay() override;
};
