// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/GameMode/F1GameMode.h"
#include "Actors/Character/Player/F1Player.h"
#include "Actors/Controller/F1PlayerController.h"

AF1GameMode::AF1GameMode()
{
	if (AF1Player::StaticClass() != NULL)
	{
		DefaultPawnClass = AF1Player::StaticClass();
	}
	if (AF1PlayerController::StaticClass() != NULL)
	{
		PlayerControllerClass = AF1PlayerController::StaticClass();
	}
}