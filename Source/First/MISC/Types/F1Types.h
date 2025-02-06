// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(Blueprintable)
enum class ECharacterID : uint8
{
	Player UMETA(DisplayName = "Player"),
	EnemyNormal UMETA(DisplayName = "NormalMonster"),
	EnemyElite UMETA(DisplayName = "EliteMonster"),
	EnemyBoss UMETA(DisplayName = "Boss"),
	NPC UMETA(DisplayName = "NPC"),
	End
};

class FIRST_API F1Types
{

};
