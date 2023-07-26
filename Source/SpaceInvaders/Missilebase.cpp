// Fill out your copyright notice in the Description page of Project Settings.


#include "Missilebase.h"
#include "Components/SphereComponent.h"
#include "Alien.h"

// Sets default values
AMissilebase::AMissilebase()
{
	myWeapon = CreateDefaultSubobject<UPlayerWeapon>(TEXT("MyWeapon"));
	myWeapon->AttachTo(RootComponent);
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent* SphereComponent =
	CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));//make collider
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(10.0f);//initial size
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));//used for collisions
	SphereComponent->SetVisibility(false);//make it visible
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	currentSpeed = 0;

}

// Called when the game starts or when spawned
void AMissilebase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMissilebase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float moveAmount = currentSpeed * DeltaTime;//calculate a small movement
	FVector currentLocation = GetActorLocation();//find out where we are
	FVector newLocation = FVector(currentLocation.X + moveAmount, currentLocation.Y, currentLocation.Z);//calculate where we going
	SetActorLocation(newLocation);//move there
}

// Called to bind functionality to input
void AMissilebase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveShip", this, &AMissilebase::Move); // move witg a & d 
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMissilebase::Shoot); // shoot one bullet with space
	PlayerInputComponent->BindAction("ShootQ", IE_Pressed, this, &AMissilebase::ShootQ); // press Q to triple shoot
}

void AMissilebase::Shoot()
{
	myWeapon->ShootOne();
}
void AMissilebase::ShootQ()
{
	myWeapon->ShootTriple();
}


void AMissilebase::Destroyed()
{
	// if the missilebase it s destroyed quit game
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController != NULL)
	{
		PController->ConsoleCommand("Quit");
	}
	
	
}


