// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NiagaraSystem.h"
#include "Engine/TargetPoint.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "FNAIController.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTESTTASK_API AFNAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USoundCue* SoundCue;

	UPROPERTY()
	UAudioComponent* AudioComponent;

	FPathFollowingRequestResult* RequestResult;
	
public:
	AFNAIController();

	UPROPERTY(EditAnywhere)
	TArray<AActor*> OutActors;
	
	FTimerHandle TimerHandle;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:

	UFUNCTION(BlueprintCallable)
	void FindTargets();
	virtual void MovingToTarget();
	void PlaySpawnSound();
	
};
