// Fill out your copyright notice in the Description page of Project Settings.


#include "FNAIController.h"

#include "Engine/TargetPoint.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AFNAIController::AFNAIController()
{
	
}

void AFNAIController::BeginPlay()
{
    Super::BeginPlay();

	FindTargets();

}


void AFNAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

		// MoveToActor(OutActors[3]);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.7f, FColor::Red, "1 sec");
		
	}, 1, false, 1.f);
	MoveToActor(OutActors[3]);
}

void AFNAIController::FindTargets()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(),OutActors);
}




