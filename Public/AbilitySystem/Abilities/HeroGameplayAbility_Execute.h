// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "HeroGameplayAbility_Execute.generated.h"

/**
 *
 */
UCLASS()
class PROJECTP_API UHeroGameplayAbility_Execute : public UWarriorHeroGameplayAbility
{
	GENERATED_BODY()

protected:

	//~ Begin UGameplayAbility Interface
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)override;
	//~ End UGameplayAbility Interface

public:


private:
	UPROPERTY(EditDefaultsOnly, Category = "Execute")
	bool Executable = false;

	UPROPERTY(EditDefaultsOnly, Category = "Execute")
	float BoxTraceDistance = 5000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Execute")
	FVector TraceBoxSize = FVector(300.f, 300.f, 300.f);

	UPROPERTY(EditDefaultsOnly, Category = "Execute")
	TArray< TEnumAsByte < EObjectTypeQuery > > BoxTraceChannel;

	UPROPERTY(EditDefaultsOnly, Category = "Execute")
	bool bShowPersistentDebugShape = false;

	UPROPERTY(EditDefaultsOnly, Category = "Execute")
	UAnimMontage* ExecuteMontage;

	UPROPERTY()
	TArray<AActor*> AvailableActorsToExecute;

	AActor* GetNearestTargetFromAvailableActors(const TArray<AActor*>& InAvailableActors); // 타겟 배열에서 가장 가까운 액터 반환

	UFUNCTION()
	void OnMontageFinished();

	UFUNCTION()
	void OnMontageCancelled();

};
