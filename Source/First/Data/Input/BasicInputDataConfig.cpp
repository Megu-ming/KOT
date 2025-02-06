// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicInputDataConfig.h"


UBasicInputDataConfig::UBasicInputDataConfig()
{
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/KOT/Input/Default/IMC_Default.IMC_Default'") };
		check(Asset.Succeeded());
		InputMappingContext = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/KOT/Input/Default/Actions/IA_Move.IA_Move'") };
		check(Asset.Succeeded());
		Move = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/KOT/Input/Default/Actions/IA_Look.IA_Look'") };
		check(Asset.Succeeded());
		Look = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/KOT/Input/Default/Actions/IA_Jump.IA_Jump'") };
		check(Asset.Succeeded());
		Jump = Asset.Object;
	}
}
