// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "First.h"
#include "Components/ActorComponent.h"
#include "F1StatusComponent.generated.h"

UENUM()
enum EStatusIndex : uint8
{
	HP,
	MP,
	Stamina,
	Damage,
	End
};

USTRUCT()
struct FStatusInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (ToolTip = "Status values for HP, MP, Stamina, and Damage."))
	int32 Status[EStatusIndex::End];
};

USTRUCT()
struct FIRST_API FStatusDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FStatusInfo Status;

	TSubclassOf<class UF1StatusComponent> StatusComponentClass;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRST_API UF1StatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UF1StatusComponent();

	virtual void SetStatusData(const FStatusDataTableRow* InData);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	FStatusInfo GetStatus() { return StatInfo; }
	int32 GetStatusValue(EStatusIndex Index) { return StatInfo.Status[Index]; }
	void SetStatus(EStatusIndex Index, int32 Value) { StatInfo.Status[Index] = Value; }
	void SetStatus(FStatusInfo Status);

protected:
	void InitStatus();

private:
	UPROPERTY(EditAnywhere, Category = "Status", meta = (AllowPrivateAccess = "true"))
	FStatusInfo StatInfo;

	const FStatusDataTableRow* StatusDataTableRow = nullptr;
};
