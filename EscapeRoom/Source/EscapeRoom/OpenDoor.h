// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);

	//Check if the total mass of objects can open the door
	float TotalMassOfActors() const;

	void AudioComponentManager();
	
private:
	//Door Rotation
	float InitialRotation;
	float CurrentRotation;
	UPROPERTY(EditAnywhere)
	float OpenDoorAngle = 90.f;

	//Pressure plate to open the door
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	UPROPERTY(EditAnywhere)
	float MassThatOpensDoor = 50.f;

	//Time before door closes
	UPROPERTY(EditAnywhere)
	float CloseDelay = 2.f;
	float TimeWhenDoorWasOpen = 0.f;

	//Open and close speed
	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 1.f;
	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 1.f;

	//Sound properties
	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;
	bool AudioPlayed = false;
};
