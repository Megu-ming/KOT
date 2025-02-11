// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Actors/Character/F1Character.h"
#include "F1Enemy_Normal.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API AF1Enemy_Normal : public AF1Character
{
	GENERATED_BODY()
	
public:
	AF1Enemy_Normal();
	
	virtual void SetData(const FDataTableRowHandle& InDataTableRowHandle) override;
	virtual void SetData(const FCharacterDataTableRow* InData) override;

protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* Weapon;

};
