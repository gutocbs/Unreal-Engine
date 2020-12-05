// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
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

	ActorThatOpensDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
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
	if(PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpensDoor))
	{
		// while(CurrentRotation != FinalRotation)
		{
			//Define rotation
			CurrentRotation = FMath::FInterpConstantTo(CurrentRotation, OpenDoorAngle, DeltaTime * DoorOpenSpeed,45);;
			GetOwner()->SetActorRotation(FRotator(0,CurrentRotation,0), ETeleportType::None);
			TimeWhenDoorWasOpen = GetWorld()->GetTimeSeconds();
		}
	}	
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	//Checa se alguma coisa pode ativar o Pressure Plate e se está ativo no momento
	if(PressurePlate && !PressurePlate->IsOverlappingActor(ActorThatOpensDoor) && TimeWhenDoorWasOpen+CloseDelay <= GetWorld()->GetTimeSeconds())
	{
		//Define rotation
		CurrentRotation = FMath::FInterpConstantTo(CurrentRotation, 0, DeltaTime * DoorCloseSpeed,45);;
		GetOwner()->SetActorRotation(FRotator(0,CurrentRotation,0), ETeleportType::None);
	}	
}



