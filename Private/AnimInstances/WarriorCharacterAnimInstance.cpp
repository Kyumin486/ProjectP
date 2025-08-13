// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/WarriorCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/WarriorBaseCharacter.h"
#include "KismetAnimationLibrary.h"
#include "Kismet/KismetMathLibrary.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{

	OwningCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}



void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent) { return; }
	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningCharacter->GetVelocity().SizeSquared2D() > 0.f;

	// 캐릭터가 보는 방향과 컨트롤러가 보는 방향 차이 값 계산
	LocomotionDirection = UKismetMathLibrary::NormalizedDeltaRotator(UKismetMathLibrary::MakeRotFromX(OwningCharacter->GetVelocity()), OwningCharacter->GetControlRotation()).Yaw;
	AILocomotionDirection = UKismetMathLibrary::NormalizedDeltaRotator(UKismetMathLibrary::MakeRotFromX(OwningCharacter->GetVelocity()), OwningCharacter->GetActorRotation()).Yaw;

	// 각도값을 -180 ~ 180 으로 제한
	LocomotionDirection = UKismetMathLibrary::NormalizeAxis(LocomotionDirection);
	AILocomotionDirection = UKismetMathLibrary::NormalizeAxis(AILocomotionDirection);

	FRotator AimOffSetRotator = UKismetMathLibrary::NormalizedDeltaRotator(OwningCharacter->GetControlRotation(), OwningCharacter->GetActorRotation());

	AimOffSetRotatorPitch = AimOffSetRotator.Pitch;

	
}


