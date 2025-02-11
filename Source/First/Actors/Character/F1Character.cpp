// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Character/F1Character.h"

#include "Components/F1StatusComponent.h"

// Sets default values
AF1Character::AF1Character()
{
	// Don't rotate when the controller rotates. Let that just affect the camera.
	
	Status = CreateDefaultSubobject<UF1StatusComponent>(TEXT("Status"));
	ID = ECharacterID::End;
}

void AF1Character::SetData(const FDataTableRowHandle& InDataTableRowHandle)
{
	DataTableRowHandle = InDataTableRowHandle;

	if (DataTableRowHandle.IsNull()) { return; }
	if (DataTableRowHandle.RowName == NAME_None) { return; }

	CharacterDataTableRow = DataTableRowHandle.GetRow<FCharacterDataTableRow>(TEXT(""));
	SetData(CharacterDataTableRow);
}

void AF1Character::SetData(const FCharacterDataTableRow* InData)
{
	CharacterDataTableRow = InData;

	if (!CharacterDataTableRow)
	{
		UE_LOG(First_Log, Warning, TEXT("%s No DataTableRow! "), *GetName());
		return;
	}

	Name = CharacterDataTableRow->Name;
	GetMesh()->SetSkeletalMesh(CharacterDataTableRow->SkeletalMesh);
	GetMesh()->SetRelativeTransform(CharacterDataTableRow->SkeletalMeshTransform);
	GetMesh()->SetAnimInstanceClass(CharacterDataTableRow->AnimInstanceClass);
		
	FStatusDataTableRow* StatusDataTableRow = CharacterDataTableRow->StatusData.GetRow<FStatusDataTableRow>(*Name);
	if (!Status)
	{
		Status = NewObject<UF1StatusComponent>(this, StatusDataTableRow->StatusComponentClass, TEXT("Status"));
		Status->RegisterComponent();
	}
	if(StatusDataTableRow)
		Status->SetStatusData(StatusDataTableRow);
}

// Called when the game starts or when spawned
void AF1Character::BeginPlay()
{
	Super::BeginPlay();

	SetData(DataTableRowHandle);
}

// Called every frame
void AF1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AF1Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

