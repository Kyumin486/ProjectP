// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/HeroGameplayAbility_Execute.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controller/WarriorHeroController.h"
#include "WarriorFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "WarriorGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Animation/AnimMontage.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"

#include "WarriorDebugHelper.h"

void UHeroGameplayAbility_Execute::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	TArray<FHitResult> BoxTraceHits;

	UKismetSystemLibrary::BoxTraceMultiForObjects(
		GetHeroCharacterFromActorInfo(),
		GetHeroCharacterFromActorInfo()->GetActorLocation(),
		GetHeroCharacterFromActorInfo()->GetActorLocation() + GetHeroCharacterFromActorInfo()->GetActorForwardVector() * BoxTraceDistance,
		TraceBoxSize / 2.f,
		GetHeroCharacterFromActorInfo()->GetActorForwardVector().ToOrientationRotator(),
		BoxTraceChannel,
		false,
		TArray<AActor*>(),
		bShowPersistentDebugShape ? EDrawDebugTrace::Persistent : EDrawDebugTrace::None,
		BoxTraceHits,
		true
	);

	for (const FHitResult& TraceHit : BoxTraceHits)
	{
		if (AActor* HitActor = TraceHit.GetActor())
		{
			if (HitActor != GetHeroCharacterFromActorInfo())
			{
				AvailableActorsToExecute.AddUnique(HitActor);

				//Debug::Print(HitActor->GetActorNameOrLabel());
			}
		}
	}

	//적 처형 가능인 지 상태 확인
	AActor* ExecutedActor = GetNearestTargetFromAvailableActors(AvailableActorsToExecute);

	if (ExecutedActor)Executable = 
		UWarriorFunctionLibrary::NativeDoesActorHaveTag(ExecutedActor, WarriorGameplayTags::Shared_Status_Executable) && 
		!UWarriorFunctionLibrary::NativeDoesActorHaveTag(ExecutedActor, WarriorGameplayTags::Enemy_Status_Boss);

	// 처형
	if (ExecutedActor && Executable)
	{
		//GetHeroCharacterFromActorInfo()->PlayAnimMontage(ExecuteMontage);

		UAbilityTask_PlayMontageAndWait* PlayExecuteMontage = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy
		(
			this,
			NAME_None,
			ExecuteMontage,
			1.0f,
			NAME_None,
			false
		);
		PlayExecuteMontage->OnCompleted.AddDynamic(this, &UHeroGameplayAbility_Execute::OnMontageFinished);
		PlayExecuteMontage->OnInterrupted.AddDynamic(this, &UHeroGameplayAbility_Execute::OnMontageCancelled);
		PlayExecuteMontage->OnCancelled.AddDynamic(this, &UHeroGameplayAbility_Execute::OnMontageCancelled);
		PlayExecuteMontage->ReadyForActivation();

		//Debug::Print(ExecutedActor->GetActorNameOrLabel());

		FGameplayEventData Data;
		Data.Target = ExecutedActor;
		Data.Instigator = GetHeroCharacterFromActorInfo();

		// 태그 전달하여 Enemy의 GA_Executed 실행
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(ExecutedActor, WarriorGameplayTags::Shared_Event_Executed, Data);

		// 회전 맞추기
		FRotator PlayerToEnemyRot = UKismetMathLibrary::FindLookAtRotation(GetHeroCharacterFromActorInfo()->GetActorLocation(), ExecutedActor->GetActorLocation());
		GetHeroCharacterFromActorInfo()->SetActorRotation(FRotator(0.f, PlayerToEnemyRot.Yaw, 0.f));

		FRotator EnemyToPlayerRot = UKismetMathLibrary::FindLookAtRotation(ExecutedActor->GetActorLocation(), GetHeroCharacterFromActorInfo()->GetActorLocation());
		ExecutedActor->SetActorRotation(FRotator(0.f, EnemyToPlayerRot.Yaw, 0.f));
	}
	else
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);

	}

}

void UHeroGameplayAbility_Execute::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

AActor* UHeroGameplayAbility_Execute::GetNearestTargetFromAvailableActors(const TArray<AActor*>& InAvailableActors)
{
	float ClosestDistance = 0.f;
	return UGameplayStatics::FindNearestActor(GetHeroCharacterFromActorInfo()->GetActorLocation(), InAvailableActors, ClosestDistance);

}

void UHeroGameplayAbility_Execute::OnMontageFinished()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}
void UHeroGameplayAbility_Execute::OnMontageCancelled()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}
