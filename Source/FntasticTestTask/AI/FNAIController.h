// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/TargetPoint.h"
#include "FNAIController.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTESTTASK_API AFNAIController : public AAIController
{
	GENERATED_BODY()
    

public:
	AFNAIController();

	UPROPERTY()
	TArray<AActor*> OutActors;
	
	FTimerHandle TimerHandle;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:

	virtual void FindTargets();
	
};
