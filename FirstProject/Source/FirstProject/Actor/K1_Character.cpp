// Fill out your copyright notice in the Description page of Project Settings.


#include "K1_Character.h"

// Sets default values
AK1_Character::AK1_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Hp = 100;
}

// Called when the game starts or when spawned
void AK1_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AK1_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AK1_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

