// Fill out your copyright notice in the Description page of Project Settings.


#include "FNAIController2.h"


void AFNAIController2::BeginPlay()
{
	Super::BeginPlay();
}


void AFNAIController2::MovingToTarget()
{
	MoveTo(OutActors[5]);
}

void AFNAIController2::RunBack()
{
	MoveTo(OutActors[2]);
}

