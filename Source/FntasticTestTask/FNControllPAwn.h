// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "FNControllPAwn.generated.h"

UCLASS()

class FNTASTICTESTTASK_API AFNControllPAwn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UCapsuleComponent* CapsuleComponent;
	
	UPROPERTY(EditAnywhere)
	UCameraComponent* CameraComponent;
	



public:
	// Sets default values for this pawn's properties
	AFNControllPAwn();
	
	UPROPERTY()
	TArray<AActor*> TargetPoints;
	
	UPROPERTY(EditAnywhere, Category = Players, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ACharacter> PlayerBlueprintType;

	TArray<TSubclassOf<ACharacter>> SpawnCharacters;

	void SpawnTurtleBase(int Index);
	void SpawnTurtle();
	void SpawnTurtle1();
	void SpawnTurtle2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
