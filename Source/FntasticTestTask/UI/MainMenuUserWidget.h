// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "MainMenuUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTESTTASK_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//UMainMenuUserWidget();

	virtual void NativeConstruct() override;

	FString PlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UEditableText* PlayerNameEditBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* StartButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* OptionsButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* ExitButton;

	UFUNCTION(BlueprintImplementableEvent)
	void ClickStart();


};
