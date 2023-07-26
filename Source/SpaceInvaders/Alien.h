// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "Alien.generated.h"


UCLASS()
class SPACEINVADERS_API AAlien : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		float speed = 10.0f;
	//UPROPERTY(EditAnywhere)
		//bool movingLeft = true;
	static bool movingLeft;
	static int numOfAliens;
	static int score ;

public:	
	// Sets default values for this actor's properties
	void Shoot();
	FTimerHandle shootTime;
	static void ChangeDirection();
	 void AddAlien();
	 void RemoveAlien();
	 int static CheckAliens(); // returns the number of aliens
		
	AAlien();
	~AAlien();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Destroyed() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, 
		class AController* EventInstigator, AActor* DamageCauser) override;
		

};
