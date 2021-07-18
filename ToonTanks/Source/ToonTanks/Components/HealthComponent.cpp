// Fill out your copyright notice in the Description page of Project Settings.
#include "HealthComponent.h"
#include "ToonTanks/GameModes/TankGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Por que isso precisaria ser checado a cada tick? Só precisamos mudar a vida em alguma função específica
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	//Inicia com vida máxima
	Health = DefaultHealth;
	//Pega o modo de jogo do mundo
	GameModeRef = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}

void UHealthComponent::TakeDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	if(Damage == 0 || Health <= 0)
		return;
	//Faz a conta de vida, não deixando ir além do minimo ou máximo
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
	if(Health <= 0)
	{
		if(GameModeRef)
			GameModeRef->ActorDied(GetOwner());
		else
			UE_LOG(LogTemp, Warning, TEXT("Health Component has no reference to the GameMode"));
	}
}

