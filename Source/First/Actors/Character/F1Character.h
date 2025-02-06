// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "First.h"
#include "GameFramework/Character.h"
#include "F1Character.generated.h"


class UF1StatusComponent;

USTRUCT()
struct FCharacterDataTableRow : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Character")
	USkeletalMesh* SkeletalMesh;

	UPROPERTY(EditAnywhere, Category = "Character")
	FTransform SkeletalMeshTransform;
	
	UPROPERTY(EditAnywhere, Category = "Character")
	TSubclassOf<UAnimInstance> AnimInstanceClass;

	UPROPERTY(EditAnywhere, meta = (RowType = "/Script/First.StatusDataTableRow"))
	FDataTableRowHandle StatusData;
};


UCLASS()
class FIRST_API AF1Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AF1Character();

	virtual void SetData(const FDataTableRowHandle& InDataTableRowHandle);
	virtual void SetData(const FCharacterDataTableRow* InData);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, meta = (RowType = "/Script/First.CharacterDataTableRow"))
	FDataTableRowHandle DataTableRowHandle;

	const FCharacterDataTableRow* CharacterDataTableRow = nullptr;

protected:
	
	
	UPROPERTY(VisibleAnywhere, Category = Status)
	UF1StatusComponent* Status;

	UPROPERTY(VisibleAnywhere, Category = ID)
	ECharacterID ID;
};
