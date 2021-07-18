// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//Include - Carrega a classe E os atributos. Serve para poder utilizar os atributos da classe
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

//foward declaration - Carrega a classe sem carregar os atributos. Serve só pra usar a classe como base
class UCapsuleComponent;
class UCapsuleComponent;
class AProjectileBase;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:
	//Componentes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta = (AllowPrivateAccess = "true"));
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
	//Variáveis
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;
	
public:
	// Sets default values for this pawn's properties
	APawnBase();
	//Como a classe base não tem movimento ou recebe inputs, podemos remover as funções que existiam aqui.
	void PawnDestroyed();
    virtual void HandleDestruction();
	
protected:
    void RotateTurret(FVector LookAtTarget);
    void Fire();
};
