// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Components/AudioComponent.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	//É necessário ter o valor inicial para fazer a porta fechar
	InitialRotation = GetOwner()->GetActorRotation().Yaw;
	CurrentRotation = InitialRotation;
	OpenDoorAngle += InitialRotation;

	if(!PressurePlate)
		UE_LOG(LogTemp, Warning, TEXT("%s does not have a PressurePlate component but has a OpenDoor component"), *GetOwner()->GetName());

	AudioComponentManager();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	OpenDoor(DeltaTime);
	CloseDoor(DeltaTime);
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	//Checa se alguma coisa pode ativar o Pressure Plate e se está ativo no momento
	if(PressurePlate && TotalMassOfActors() >= MassThatOpensDoor)
	{
		//Define rotation
		CurrentRotation = FMath::FInterpConstantTo(CurrentRotation, OpenDoorAngle, DeltaTime * DoorOpenSpeed,45);;
		GetOwner()->SetActorRotation(FRotator(0,CurrentRotation,0), ETeleportType::None);
		TimeWhenDoorWasOpen = GetWorld()->GetTimeSeconds();
		if(!AudioComponent->IsPlaying() && AudioPlayed == false)
		{
			AudioComponent->Play();
			AudioPlayed = true;
		}
	}	
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	//Checa se alguma coisa pode ativar o Pressure Plate e se está ativo no momento
	if(PressurePlate && TotalMassOfActors() < MassThatOpensDoor && TimeWhenDoorWasOpen != 0.f && TimeWhenDoorWasOpen+CloseDelay <= GetWorld()->GetTimeSeconds())
	{
		//Define rotation
		CurrentRotation = FMath::FInterpConstantTo(CurrentRotation, 0, DeltaTime * DoorCloseSpeed,45);;
		GetOwner()->SetActorRotation(FRotator(0,CurrentRotation,0), ETeleportType::None);
		if(!AudioComponent->IsPlaying() && AudioPlayed == true)
		{
			AudioComponent->Play();
			AudioPlayed = false;
		}
	}	
}

float UOpenDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;
	//Find all overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OverlappingActors);
	for (AActor* OverlappingActor : OverlappingActors)
		TotalMass += OverlappingActor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	// UE_LOG(LogTemp, Warning, TEXT("Total mass %f"), TotalMass);
	return TotalMass;
}

void UOpenDoor::AudioComponentManager()
{
	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	if(!AudioComponent)
		UE_LOG(LogTemp, Error, TEXT("Não foi possível encontrar AudioComponent no componente %s"), *GetOwner()->GetName());
}
