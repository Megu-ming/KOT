// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "K1_Character.generated.h"

UCLASS()
class FIRSTPROJECT_API AK1_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AK1_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere)
	int32 Hp;
};
