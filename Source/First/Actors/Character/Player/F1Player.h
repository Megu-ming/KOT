// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "First.h"
#include "Actors/Character/F1Character.h"
#include "F1Player.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class FIRST_API AF1Player : public AF1Character
{
	GENERATED_BODY()
	
public:
	AF1Player();

	virtual void SetData(const FDataTableRowHandle& InDataTableRowHandle) override;
	virtual void SetData(const FCharacterDataTableRow* InData) override;

public:
	void Attack();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* SpringArm;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* Camera;
	
};
