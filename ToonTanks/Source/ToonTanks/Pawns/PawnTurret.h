// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:
	void CheckFireCondition();
	float ReturnDistanceToPlayer();

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess  = true))
	float FireRate= 0.5f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess  = true))
	float FireRange= 500.0f;
	
	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;
public:
	//A classe Tank irá se mover e receber inputs, então precisa das classes abaixo	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};
