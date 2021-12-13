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
	
}

void AFNAIController1::MovingToTarget()
{
	MoveTo(OutActors[4]);

}

