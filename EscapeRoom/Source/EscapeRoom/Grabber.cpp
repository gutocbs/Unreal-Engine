// Fill out your copyright notice in the Description page of Project Settings.

#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	PhysicsHandleManager();
	InputManager();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// HitManager();
}

void UGrabber::PhysicsHandleManager()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if(!PhysicsHandle)
		UE_LOG(LogTemp, Error, TEXT("Não foi possível encontrar PhysicsHandle no componente %s"), *GetOwner()->GetName())
}

void UGrabber::InputManager()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if(InputComponent)
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
}

void UGrabber::HitManager()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation,OUT PlayerViewPointRotation);
	DrawDebugLine(
        GetWorld(),
        PlayerViewPointLocation,
        LineTraceEnd,
        FColor(0,255,0),
        false,
        0.f,
        0,
        5.f
    );
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grabber text"));
	FHitResult HitResult = GetFirstPhysicsBodyInReach();	
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation,OUT PlayerViewPointRotation);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
	
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
        OUT Hit,
        PlayerViewPointLocation,
        LineTraceEnd,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
        TraceParams
    );

	AActor* ActorHit = Hit.GetActor();
	if(ActorHit)
		UE_LOG(LogTemp, Warning, TEXT("HIT %s"), *ActorHit->GetName());

	return Hit;
}

