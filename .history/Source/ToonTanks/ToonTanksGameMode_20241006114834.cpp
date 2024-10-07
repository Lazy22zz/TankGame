// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
    if(DeadActor == Tank)
    {
        Tank -> HandleDestruction();
        if (Tank->GetTankPlayerController())
        {
            Tank -> DisableInput(Tank->GetTankPlayerController());
        }
    }
}

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();

    Tank = cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}