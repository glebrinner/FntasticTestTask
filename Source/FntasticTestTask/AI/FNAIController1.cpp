// Fill out your copyright notice in the Description page of Project Settings.


#include "FNAIController1.h"

AFNAIController1::AFNAIController1()
{
	
}

void AFNAIController1::BeginPlay()
{
	Super::BeginPlay();

	FindTargets();
}


void AFNAIController1::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
	{
		UE_LOG(LogTemp, Warning, TEXT("This text will appear in the console 3 seconds after execution"))
		MoveToActor(OutActors[4]);
	}, 1, false);
	
}