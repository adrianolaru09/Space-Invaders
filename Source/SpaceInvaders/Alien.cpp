// Fill out your copyright notice in the Description page of Project Settings.


#include "Alien.h"
#include "Bullet.h"
#include "TimerManager.h"
#include "Missilebase.h"

bool AAlien::movingLeft = true;
int AAlien::numOfAliens = 0;
int AAlien::score = -60;

void AAlien::Shoot() //aliens shooting 
{
	const FRotator FireRotation = FRotator(0.f, 0.f, 0.f);
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		// spawn the projectile
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		ABullet* thisBullet = World->SpawnActor<ABullet>(GetActorLocation() + FVector(0.f, 0.f, -35.f), FireRotation, SpawnParams);
		thisBullet->FireInDirection(FVector(0.f, 0.f, -1.f));
	}
}

void AAlien::ChangeDirection() // aliens movement
{
	movingLeft =! movingLeft;
}

void AAlien::AddAlien() 
{
	numOfAliens++;
	//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, FString::Printf(TEXT("alien left: %i "), numOfAliens));
}

void AAlien::RemoveAlien()
{
	numOfAliens--;
	score += 10;
	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red,FString::Printf(TEXT("alien left: %i  "),numOfAliens)) ;
		//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, FString::Printf(TEXT("score: %i  "), score));
	}
	if (numOfAliens == 0)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			numOfAliens = 0;
			score = -60;
			World->GetFirstPlayerController()->ConsoleCommand("Quit");
		}
	}
}

int AAlien::CheckAliens() //returns the number of aliens
{
	return numOfAliens;
}

// Sets default values
AAlien::AAlien()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent* SphereComponent =
		CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));//makes the collider
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(20.0f);// Sets the Initial Size  // initial a fost 40 in caz ca nu e asta
	SphereComponent->SetCollisionProfileName(TEXT("PAWN"));// used for collisions
	SphereComponent->SetVisibility(false);//make it invisible

}

// Called when the game starts or when spawned
void AAlien::BeginPlay()
{
	Super::BeginPlay();
	AAlien::AddAlien(); // adds aliens to the counter 
	GetWorldTimerManager().SetTimer(shootTime, this, &AAlien::Shoot, 1.0f, true, 2.0f); //shooting
}

void AAlien::Destroyed()
{
	RemoveAlien();
}

AAlien::~AAlien()
{
	numOfAliens = 0;
}

// Called every frame
void AAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector goTo = GetActorLocation();//where we are
	int direction = -1;
	
	if (!movingLeft)//if we aren't going left , change direction
	{
		direction = 1;
	}
	goTo.X += DeltaTime * speed * direction; // change to where we are going 
	SetActorLocation(goTo);
	if ((goTo.X < -250.0f) || (goTo.X > 250.0f))
	{
		AAlien::ChangeDirection();
	}
}
float AAlien::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Destroy();
	return 0.0f;
}

