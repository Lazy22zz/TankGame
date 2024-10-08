// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:


private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArmCom;

	UPROPERTY(VisibleAnyWhere)
	class UCameraComponent* Camera;
};
