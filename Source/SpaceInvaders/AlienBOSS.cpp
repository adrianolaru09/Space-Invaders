// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienBOSS.h"

AAlienBOSS::AAlienBOSS()
{

	bossSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BossSprite"));
	bossSprite->AttachTo(RootComponent);
	bossSprite->SetSprite(ConstructorHelpers::FObjectFinder<UPaperSprite>(TEXT("/Game/Images/alien1_Sprite.alien1_Sprite")).Object);
	bossSprite->SetSpriteColor(FLinearColor::Yellow);
	//on hit
	bossSprite->OnComponentHit.AddDynamic(this, &AAlienBOSS::OnHit);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BossMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	//create mesh component for the shield sphere
	bossMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BossMesh0"));
	bossMesh->SetStaticMesh(BossMeshAsset.Object);
	bossMesh->SetupAttachment(RootComponent);
	bossMesh->BodyInstance.SetCollisionProfileName("Pawn");
	bossMesh->SetRelativeScale3D(FVector(0.7f, 0, 0.6f));
	FVector NewLocation = FVector(0, -30.f, -30.f); // "behind" the sprite
	bossMesh->SetRelativeLocation(NewLocation);
	
}

void AAlienBOSS::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
			aliensLeft = AAlien::CheckAliens(); // reference to the number of aliens
			if (aliensLeft <= 1) // if boss alien last and hit -> destroy 
			{
				Destroy();
			}
			if (GEngine)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, FString::Printf(TEXT("ATATIA MAI SUNT ALIENS BOSSS E OKKK: %i  "), aliensLeft));
			}
}

void AAlienBOSS::BeginPlay()
{
	Super::BeginPlay();

}
