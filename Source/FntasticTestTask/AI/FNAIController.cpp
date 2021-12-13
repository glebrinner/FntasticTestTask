// Fill out your copyright notice in the Description page of Project Settings.


#include "FNAIController.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AFNAIController::AFNAIController()
{
	static ConstructorHelpers::FObjectFinder<USoundCue> StartSound(TEXT("/Game/Sounds/NotifSound/SCue"));
	SoundCue = StartSound.Object;
	
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
    AudioComponent->bAutoActivate = false;
}

void AFNAIController::BeginPlay()
{
    Super::BeginPlay();
	FindTargets();
    PlaySpawnSound();

}


void AFNAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	MovingToTarget();
}

void AFNAIController::FindTargets()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(),OutActors);
}

void AFNAIController::MovingToTarget()
{
	TSubclassOf<UNavigationQueryFilter> Filter;
	MoveToActor(OutActors[3], 50,true, true, true, Filter,true);
}

void AFNAIController::PlaySpawnSound()
{
	if (SoundCue->IsValidLowLevelFast()) {
		AudioComponent->SetSound(SoundCue);
	}
 
	AudioComponent->Play();
}
