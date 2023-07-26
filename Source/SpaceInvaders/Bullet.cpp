// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Alien.h"

void ABullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherActor != GetOwner()))
	{
			if (OtherActor->IsA(ASpriteAlien::StaticClass()) || OtherActor->IsA(AAlienBOSS::StaticClass()))
			{

				if (!GetOwner()->IsA(AAlien::StaticClass()))
				{

					//DealDamage(OtherActor); // deal damage for the aliens the player shoots
				}
			}
			else {
				OtherActor->Destroy();
			}
			Destroy();
	}

}

void ABullet::FireInDirection(const FVector& ShootDirection)
{
	projectileMovement->Velocity = ShootDirection * projectileMovement->InitialSpeed;
}

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	//create mesh component for the projectile sphere
	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	projectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	projectileMesh->SetupAttachment(RootComponent);
	projectileMesh->BodyInstance.SetCollisionProfileName("Pawn");
	projectileMesh->OnComponentHit.AddDynamic(this, &ABullet::OnHit);
	projectileMesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	//set up a notification for when this component hits something 
	RootComponent = projectileMesh;

	//move projecetile mesh, set its speed, ignore ravity, do not bounce
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	projectileMovement->UpdatedComponent = projectileMesh;
	projectileMovement->InitialSpeed = 300.f;
	projectileMovement->MaxSpeed = 300.f;
	projectileMovement->bRotationFollowsVelocity = true;
	projectileMovement->bShouldBounce = false;
	projectileMovement->ProjectileGravityScale = 0.f; // No gravity
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

void ABullet::DealDamage(AActor* victim)
{
	float damageAmount = 1.0f;
	FDamageEvent bulletDamageEvent;
	AController* PController = GetWorld()->GetFirstPlayerController();
	victim->TakeDamage(damageAmount, bulletDamageEvent, PController, this);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

