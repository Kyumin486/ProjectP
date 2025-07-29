// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "HeroGameplayAbility_PickUpHeal.generated.h"

class AWarriorHealBase;
/**
 * 
 */
UCLASS()
class PROJECTP_API UHeroGameplayAbility_PickUpHeal : public UWarriorHeroGameplayAbility
{
	GENERATED_BODY()

protected:

	//~ Begin UGameplayAbility Interface
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)override;
	//~ End UGameplayAbility Interface

	UFUNCTION(BlueprintCallable)
	void CollectHeal();

	UFUNCTION(BlueprintCallable)
	void ConsumeHeal();

private:
	UPROPERTY(EditDefaultsOnly)
	FVector TraceBoxSize = { 50,50,50 };

	UPROPERTY(EditDefaultsOnly)
	TArray<TEnumAsByte<EObjectTypeQuery>> TraceChannel;

	UPROPERTY(EditDefaultsOnly)
	bool bTraceComplex;

	UPROPERTY(EditDefaultsOnly)
	bool DrawDebugTrace = false;

	UPROPERTY()
	TArray<AWarriorHealBase*> CollectHealArray;
};
