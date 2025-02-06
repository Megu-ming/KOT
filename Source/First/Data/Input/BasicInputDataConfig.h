// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "BasicInputDataConfig.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API UBasicInputDataConfig : public UObject
{
	GENERATED_BODY()
	
public:
	UBasicInputDataConfig();
	UInputMappingContext* InputMappingContext = nullptr;

	UInputAction* Move = nullptr;
	UInputAction* Look = nullptr;
	UInputAction* Jump = nullptr;
};
