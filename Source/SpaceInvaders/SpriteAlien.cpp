// Fill out your copyright notice in the Description page of Project Settings.


#include "SpriteAlien.h"



ASpriteAlien::ASpriteAlien()
{
	//create sprite component
	alienSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("AlienSprite"));
	alienSprite->AttachTo(RootComponent);
	alienSprite->SetSprite(ConstructorHelpers::FObjectFinder<UPaperSprite>(TEXT("/Game/Images/alien1_Sprite.alien1_Sprite")).Object);
	//on hit add dynamic
	alienSprite->OnComponentHit.AddDynamic(this, &ASpriteAlien::OnHit);
}

void ASpriteAlien::ChangeColor()
{ 
	alienSprite->SetSpriteColor(FLinearColor::Red);
}

void ASpriteAlien::ChangeColorGreen()
{
	alienSprite->SetSpriteColor(FLinearColor::Green);
}

void ASpriteAlien::ChangeColorBlue()
{
	alienSprite->SetSpriteColor(FLinearColor::Blue);
}

void ASpriteAlien::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	hitTimes++;
	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, FString::Printf(TEXT("hit times: %i "), hitTimes));
	}
	
	if (hitTimes == 1) {
		ChangeColorGreen(); // first hit change color green
	}
	else if (hitTimes == 2)
	{
		ChangeColor(); // second hit change color red
	}
	else if (hitTimes == 3)
	{
		ChangeColorBlue(); // third hit change color bblue
	}
	else if (hitTimes > 3)
	{
		Destroy(); // destroy on the 4th  hit
	}
}

void ASpriteAlien::BeginPlay()
{
	Super::BeginPlay();
}
