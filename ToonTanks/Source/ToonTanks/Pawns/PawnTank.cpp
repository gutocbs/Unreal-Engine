// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APawnTank::APawnTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}


// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();
	PLayerControllerRef = Cast<APlayerController>(GetController());
	
}

void APawnTank::HandleDestruction()
{
	Super::HandleDestruction();
	//TODO Fazer o tank morrer
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Primeiro decide a direção
	Rotate();
	//Depois se movimenta
	Move();

	if(PLayerControllerRef)
	{
		FHitResult TraceHitResult;
		//Função pega a direção pra onde o mouse aponta
		PLayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);
		//Pega o ponto específico do mouse
		FVector HitLocation = TraceHitResult.ImpactPoint;
		//Gira naquela direção
		RotateTurret(HitLocation);
	}
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);
	//BindAction é usado para botões que são apertados para fazer ações, como atirar, pular, usar um item.
	//A diferença disso pro BindAxis é que o Axis cuida apenas de movimentos. Além disso, o Action pode APERTAR e SOLTAR o botão
	//Ex: Apertar-> começa a atirar. Soltar -> para de atirar
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);

}

void APawnTank::CalculateMoveInput(float Value)
{
	//DeltaTimeSeconds serve para sincronizar o movimento com os frames. Sem isso, o movimento será irregular entre os frames
	//Ex sem delta time: Frame 1 - Duas unidades de movimento, Frame 2 - 80 unidades de movimento, Frame 3 - 28 unidades de movimento
	//Ex com delta time: Fame 1 - Duas unidades de movimento, Frame 2 - Duas unidades de movimento, Frame 3 - duas unidades de movimento
	MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APawnTank::CalculateRotateInput(float Value)
{
	float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds; 
	FRotator Rotation = FRotator(0, RotateAmount,0);
	RotationDirection = FQuat(Rotation);
}

void APawnTank::Move()
{
	//bSweep = true -> Checar por colisões na hora de se movimentar
	AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate()
{
	AddActorLocalRotation(RotationDirection, true);
}
