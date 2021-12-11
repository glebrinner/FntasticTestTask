// Fill out your copyright notice in the Description page of Project Settings.


#include "FNControllPAwn.h"

#include "Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFNControllPAwn::AFNControllPAwn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<ACharacter> Char(TEXT("Blueprint'/Game/SpawnedCharacter'"));
	static ConstructorHelpers::FClassFinder<ACharacter> Char1(TEXT("Blueprint'/Game/SpawnedCharacter1'"));
	static ConstructorHelpers::FClassFinder<ACharacter> Char2(TEXT("Blueprint'/Game/SpawnedCharacter2'"));
	SpawnCharacters.Add(Char.Class);
	SpawnCharacters.Add(Char1.Class);
	SpawnCharacters.Add(Char2.Class);

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(CapsuleComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CapsuleComponent);

}

// Called when the game starts or when spawned
void AFNControllPAwn::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), TargetPoints);
}

// Called every frame
void AFNControllPAwn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFNControllPAwn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("First", IE_Pressed, this, &AFNControllPAwn::SpawnTurtle);
	PlayerInputComponent->BindAction("Second", IE_Pressed, this, &AFNControllPAwn::SpawnTurtle1);
	PlayerInputComponent->BindAction("Third", IE_Pressed, this, &AFNControllPAwn::SpawnTurtle2);

}

void AFNControllPAwn::SpawnTurtleBase(int Index)
{
	if(Index == 0)
	{
		for(AActor* Point : TargetPoints)
		{
			if(Point->GetActorLabel() == "TargetPoint1")
			{
				FActorSpawnParameters SpawnParams;
				GetWorld()->SpawnActor<ACharacter>(SpawnCharacters[Index], Point->GetActorLocation(), Point->GetActorRotation(), SpawnParams);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Point->GetActorLabel() + " Spawned");
			}
		
		}
	}
	
	if(Index == 1)
    	{
    		for(AActor* Point : TargetPoints)
    		{
    			if(Point->GetActorLabel() == "TargetPoint2")
    			{
    				FActorSpawnParameters SpawnParams;
    				GetWorld()->SpawnActor<ACharacter>(SpawnCharacters[Index], Point->GetActorLocation(), Point->GetActorRotation(), SpawnParams);
    				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Point->GetActorLabel() + " Spawned");
    			}
    		
    		}
    	}

	if(Index == 2)
	{
		for(AActor* Point : TargetPoints)
		{
			if(Point->GetActorLabel() == "TargetPoint3")
			{
				FActorSpawnParameters SpawnParams;
				GetWorld()->SpawnActor<ACharacter>(SpawnCharacters[Index], Point->GetActorLocation(), Point->GetActorRotation(), SpawnParams);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Point->GetActorLabel() + " Spawned");
			}
		
		}
	}
}

void AFNControllPAwn::SpawnTurtle()
{
	SpawnTurtleBase(0);
}

void AFNControllPAwn::SpawnTurtle1()
{
	SpawnTurtleBase(1);
}

void AFNControllPAwn::SpawnTurtle2()
{
	SpawnTurtleBase(2);
}