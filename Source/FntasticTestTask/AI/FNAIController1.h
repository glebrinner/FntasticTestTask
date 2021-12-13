// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FNAIController.h"
#include "FNAIController1.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTESTTASK_API AFNAIController1 : public AFNAIController
{
	GENERATED_BODY()

	AFNAIController1();


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UFUNCTION(BlueprintCallable)
	virtual void MovingToTarget() override;
};
