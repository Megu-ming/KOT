// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Character/Enemy/F1Enemy_Normal.h"

AF1Enemy_Normal::AF1Enemy_Normal()
{
	ID = ECharacterID::EnemyNormal;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	FString SocketName = TEXT("hand_l");
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, *SocketName);
}

void AF1Enemy_Normal::SetData(const FDataTableRowHandle& InDataTableRowHandle)
{
	Super::SetData(InDataTableRowHandle);
}

void AF1Enemy_Normal::SetData(const FCharacterDataTableRow* InData)
{
	Super::SetData(InData);

	Weapon->SetSkeletalMesh(InData->WeaponSkeletalMesh);
	Weapon->SetRelativeTransform(InData->WeaponTransform);
}

void AF1Enemy_Normal::BeginPlay()
{
	Super::BeginPlay();
}
