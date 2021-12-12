// Fill out your copyright notice in the Description page of Project Settings.


#include "FNAIController1.h"

AFNAIController1::AFNAIController1()
{
	
}

void AFNAIController1::BeginPlay()
{
	Super::BeginPlay();

	FindTargets();
	for(AActor* Targets : OutActors)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Targets->GetActorLabel() + " Finded");
	}
}


void AFNAIController1::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
	// FTimerHandle TimerHandle;
	// GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("This text will appear in the console 3 seconds after execution"))
	// 	
	// }, 1, false);
	// FTimerHandle TimerHandle;
	// GetWorld()->GetTimerManager().SetTimer(TimerHandle, 5, true, 1);
	// GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFNAIController1::MovingToTarget, 1, true, 1);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFNAIController1::MovingToTarget, 1, true);

	//MoveToActor(OutActors[4]);
}

void AFNAIController1::MovingToTarget()
{
	MoveTo(OutActors[4]);
}
