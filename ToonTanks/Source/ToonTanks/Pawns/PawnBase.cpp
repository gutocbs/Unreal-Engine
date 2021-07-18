// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "ToonTanks/Actors/ProjectileBase.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CapsuleComp é a hitbox do objeto. Setamos o RootComponent para ser a hitbox por que é a hitbox que vai se movimentar, o que faz o objeto se movimentar junto.
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	//O Mesh do pawn tem que ser ligado à hitbox, para que possa se mover
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	//No caso, o turretMesh é a "cabeça" do mesh, que se move independente do corpo. Porém, ela tem que ficar sempre ligada ao corpo (baseMesh)
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	//Os tiros vão sair de onde? Da torre. Então o ponto de spawn do tiro tem que estar conectado à torre
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector LookAtTarget){
	const FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y,TurretMesh->GetComponentLocation().Z);
	const FVector StartLocation = TurretMesh->GetComponentLocation();
	const FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();
    TurretMesh->SetWorldRotation(TurretRotation);
}
void APawnBase::Fire(){
	if(ProjectileClass)
	{
		const FVector SpawnLoation = ProjectileSpawnPoint->GetComponentLocation();
		const FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();
		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, SpawnLoation, SpawnRotation);
		//Com isso, o projeto não irá causar dano ao tocar o tank. Não causa dano no seu dono
		TempProjectile->SetOwner(this);
	}
}
void APawnBase::HandleDestruction(){
}