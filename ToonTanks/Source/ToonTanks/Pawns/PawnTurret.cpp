// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"

#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this,0));
}

void APawnTurret::HandleDestruction()
{
	//Chama a função da classe base antes de iniciar sua própria função
	Super::HandleDestruction();
	Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
		return;
	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	if(!PlayerPawn)
		return;
	if(ReturnDistanceToPlayer() <= FireRange)
		Fire();
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if(!PlayerPawn)
		return 0.0f;

	//No caso, quando não especifico qual o objeto que está chamando GetActorLocation, estou definindo o root como objeto base
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
