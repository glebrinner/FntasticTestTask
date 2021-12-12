// Fill out your copyright notice in the Description page of Project Settings.


#include "FNAIController.h"

#include "NiagaraFunctionLibrary.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AFNAIController::AFNAIController()
{
	// static ConstructorHelpers::FClassFinder<UNiagaraEmitter> NiagaraEffect(TEXT("Blueprint'/Game/SpawnedCharacter'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> FinishSound(TEXT("/Game/Sounds/FinishSound/FinishCue"));
	SoundCue = FinishSound.Object;
	
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PropellerAudioComp"));
//    AudioComponent->SetRelativeLocation(GetOwner()->GetActorLocation());
    AudioComponent->bAutoActivate = false;
}

void AFNAIController::BeginPlay()
{
    Super::BeginPlay();
	FindTargets();
    SpawnFinishEffects();
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
	
	//RequestResult->MoveId = 1;
    //MoveTo(OutActors[3]);
	MoveToActor(OutActors[3], 100,true, true, true, Filter,true);
//	if(!RequestResult->Code)
//	{
//		SpawnFinishEffects();
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Request Working");
//	}
}

void AFNAIController::SpawnStartUpEffect()
{
	if(NiagaraTemplate)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraTemplate,
		GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation(),
		FVector(1,1, 1),true,true);
	}

}

void AFNAIController::SpawnFinishEffects()
{
	
	if (SoundCue->IsValidLowLevelFast()) {
		AudioComponent->SetSound(SoundCue);
	}
 
	AudioComponent->Play();
	
}
