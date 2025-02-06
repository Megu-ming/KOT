// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "AttackInputDataConfig.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API UAttackInputDataConfig : public UObject
{
	GENERATED_BODY()
	
public:
	UAttackInputDataConfig();
	UInputMappingContext* InputMappingContext = nullptr;

	UInputAction* Attack = nullptr;
};
