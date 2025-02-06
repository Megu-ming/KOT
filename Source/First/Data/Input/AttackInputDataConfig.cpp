// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackInputDataConfig.h"

UAttackInputDataConfig::UAttackInputDataConfig()
{
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/KOT/Input/Attack/IMC_Attack.IMC_Attack'") };
		check(Asset.Succeeded());
		InputMappingContext = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/KOT/Input/Attack/IA_Attack.IA_Attack'") };
		check(Asset.Succeeded());
		Attack = Asset.Object;
	}
}
