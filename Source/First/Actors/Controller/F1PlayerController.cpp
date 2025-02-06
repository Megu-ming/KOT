// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Controller/F1PlayerController.h"
#include "Data/Input/BasicInputDataConfig.h"
#include "Data/Input/AttackInputDataConfig.h"
#include "GameFramework/Character.h"
#include "Actors/CameraManager/F1PlayerCameraManager.h"
#include "Actors/Character/Player/F1Player.h"

AF1PlayerController::AF1PlayerController()
{
	PlayerCameraManagerClass = AF1PlayerCameraManager::StaticClass();
}

void AF1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	const UBasicInputDataConfig* BasicInputDataConfig = GetDefault<UBasicInputDataConfig>();
	const UAttackInputDataConfig* AttackInputDataConfig = GetDefault<UAttackInputDataConfig>();
	Subsystem->AddMappingContext(BasicInputDataConfig->InputMappingContext, 0);
	Subsystem->AddMappingContext(AttackInputDataConfig->InputMappingContext, 0);

	SetControlRotation(FRotator(-30., 0., 0.));
}

void AF1PlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (IsValid(Cast<AF1Player>(aPawn)))
	{
		PlayerCharacter = Cast<AF1Player>(aPawn);
	}
}

void AF1PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	ensure(EnhancedInputComponent);

	const UBasicInputDataConfig* InputDataConfig = GetDefault<UBasicInputDataConfig>();
	const UAttackInputDataConfig* AttackInputDataConfig = GetDefault<UAttackInputDataConfig>();
	EnhancedInputComponent->BindAction(InputDataConfig->Move, ETriggerEvent::Triggered, this, &ThisClass::OnMove);
	EnhancedInputComponent->BindAction(InputDataConfig->Look, ETriggerEvent::Triggered, this, &ThisClass::OnLook);
	EnhancedInputComponent->BindAction(InputDataConfig->Jump, ETriggerEvent::Started, this, &ThisClass::OnJump);
	EnhancedInputComponent->BindAction(InputDataConfig->Jump, ETriggerEvent::Completed, this, &ThisClass::StopJump);
	EnhancedInputComponent->BindAction(AttackInputDataConfig->Attack, ETriggerEvent::Started, this, &ThisClass::OnAttack);
}

void AF1PlayerController::OnMove(const FInputActionValue& InputActionValue)
{
	if(PlayerCharacter)
	{
		USkeletalMeshComponent* SkeletalMeshComponent = PlayerCharacter->GetComponentByClass<USkeletalMeshComponent>();
		if (!SkeletalMeshComponent)
		{
			ensure(false);
			return;
		}
		const FRotator Rotation = K2_GetActorRotation();
		const FRotator YawRotation = FRotator(0., Rotation.Yaw, 0.);
		const FVector ForwardVector = YawRotation.Vector();
		const FVector RightVector = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::Y);

		const FVector ActionValue = InputActionValue.Get<FVector>();
		PlayerCharacter->AddMovementInput(ForwardVector, ActionValue.Y);
		PlayerCharacter->AddMovementInput(RightVector, ActionValue.X);
	}


	UpdateRotation(1.f);
}

void AF1PlayerController::OnLook(const FInputActionValue& InputActionValue)
{
	const FVector ActionValue = InputActionValue.Get<FVector>();
	AddYawInput(ActionValue.X);
	AddPitchInput(ActionValue.Y);
}

void AF1PlayerController::OnJump()
{
	PlayerCharacter->Jump();
}

void AF1PlayerController::StopJump()
{
	PlayerCharacter->StopJumping();
}

void AF1PlayerController::OnAttack()
{
	PlayerCharacter->Attack();
}
