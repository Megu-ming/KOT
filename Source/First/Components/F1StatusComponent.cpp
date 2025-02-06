// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/F1StatusComponent.h"


// Sets default values for this component's properties
UF1StatusComponent::UF1StatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UF1StatusComponent::SetStatusData(const FStatusDataTableRow* InData)
{
	ensure(InData);

	StatusDataTableRow = InData;
	InitStatus();
}


// Called when the game starts
void UF1StatusComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UF1StatusComponent::InitStatus()
{
	if(StatusDataTableRow)
	{
		UE_LOG(First_Log, Warning, TEXT("SetStatus"));
		SetStatus(StatusDataTableRow->Status);
	}
}