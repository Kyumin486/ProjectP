// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/HeroGameplayAbility_PickUpHeal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Items/PickUps/WarriorHealBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

void UHeroGameplayAbility_PickUpHeal::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UHeroGameplayAbility_PickUpHeal::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UHeroGameplayAbility_PickUpHeal::CollectHeal()
{
	CollectHealArray.Empty();

	TArray<FHitResult> HitResult;

	// 주변에 힐 아이템 있는 지 트레이스하여 확인
	UKismetSystemLibrary::BoxTraceMultiForObjects
	(
		this,
		GetAvatarActorFromActorInfo()->GetActorLocation(),
		GetAvatarActorFromActorInfo()->GetActorLocation() + -GetAvatarActorFromActorInfo()->GetActorUpVector() * 100,
		TraceBoxSize,
		FRotator::ZeroRotator,
		TraceChannel,
		bTraceComplex,
		TArray<AActor*>(),
		DrawDebugTrace ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
		HitResult,
		true
	);

	// 트레이스 된 힐을 배열에 저장
	for (FHitResult& Hit : HitResult)
	{
		if (AWarriorHealBase* FoundHeal = Cast<AWarriorHealBase>(Hit.GetActor()))
		{
			CollectHealArray.AddUnique(FoundHeal);

		}
	}

	if (CollectHealArray.IsEmpty())
	{
		CancelAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true);
	}
}

void UHeroGameplayAbility_PickUpHeal::ConsumeHeal()
{
	if (CollectHealArray.IsEmpty())
	{
		CancelAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true);
	}

	for (AWarriorHealBase* CollectHeal : CollectHealArray)
	{
		if (CollectHeal)
		{
			CollectHeal->Consume(GetWarriorAbilitySystemComponentFromActorInfo(), GetAbilityLevel());
		}

	}
}
