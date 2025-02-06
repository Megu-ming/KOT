// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "F1PlayerController.generated.h"

class AF1Player;

UCLASS()
class FIRST_API AF1PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AF1PlayerController();

	virtual void BeginPlay() override;
	
	virtual void OnPossess(APawn* aPawn) override;

	virtual void SetupInputComponent() override;
	
protected:
	void OnMove(const FInputActionValue& InputActionValue);
	void OnLook(const FInputActionValue& InputActionValue);
	void OnJump();
	void StopJump();
	void OnAttack();

protected:
	AF1Player* PlayerCharacter;
};
