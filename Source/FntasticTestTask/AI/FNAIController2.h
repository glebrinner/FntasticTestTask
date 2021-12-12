// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FNAIController.h"
#include "FNAIController2.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTESTTASK_API AFNAIController2 : public AFNAIController
{
	GENERATED_BODY()

protected:
	virtual void MovingToTarget() override;
	
};
