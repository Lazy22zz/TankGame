// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

ATank::ATank()
{
    SpringArmCom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArmCom -> SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera -> SetupAttachment(SpringArmCom);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent -> BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent -> BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::Move(float value)
{
    FVector DeltaLocation = FVector::ZeroVector; // x,y,z is 0
    DeltaLocation.X = value * UGameplayStatics::GetWorldDeltaSeconds(this) * speed;
    AddActorLocalOffset(DeltaLocation, true);

}

void ATank::Turn(float value)
{
    FRotator DeltaRotation = FRotator::ZeroRotator;
    DeltaRotation.Yaw = value * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnRate;
    AddActorLocalRotation(DeltaRotation, true);
    
}