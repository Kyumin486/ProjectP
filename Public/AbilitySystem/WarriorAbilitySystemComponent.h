// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WarriorAbilitySystemComponent.generated.h"

struct FWarriorHeroAbilitySet;
/**
 *
 */
UCLASS()
class PROJECTP_API UWarriorAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()


public:

	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability", meta = (ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, const TArray<FWarriorHeroSpecialAbilitySet>& InSpecialWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantAbilitySpecHandles);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	void RemovedGrantedHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	bool TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	void TryCancelAbilityByTag(FGameplayTag AbilityTagToCancel);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	void SetAbilityLevelByTag(FGameplayTag AbilityTag); // ��ų ���� +1 �Լ�

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	UGameplayAbility* FindAbilityByTag(FGameplayTag AbilityTag); // ��ų ã�� �Լ�

public:

	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Ability")
	int32 KatanaSkillLevel{ 1 };

	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Ability")
	int32 BowSkillLevel{ 1 };

};
