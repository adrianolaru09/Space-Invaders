// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "Bullet.h"
#include "PlayerWeapon.h"
#include "Alien.h"
#include "Missilebase.generated.h"

UCLASS()
class SPACEINVADERS_API AMissilebase : public APawn
{
	GENERATED_BODY()

public:
	void Move(float amount) { currentSpeed = FMath::Clamp(amount, -1.0f, 1.0f) * 100; };
	void Shoot(); // shoot with space
	void ShootQ(); // shoot explosive bullet with Q 
	float currentSpeed;
	
public:
	// Sets default values for this pawn's properties
	AMissilebase();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Destroyed() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPlayerWeapon* myWeapon; // player weapon reference

};
