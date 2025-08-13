// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AWarriorHeroCharacter;
class AWarriorHeroController;
class UHeroCombatComponent;
/**
 *
 */
UCLASS()
class PROJECTP_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	// ���� �ɷ�ġ�� ����� �������� �����ϴ�  FGameplayEffectSpecHandle ��ȯ
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect>EffectClass, float InWeaponDamage);

	// �±׿� �´� ��ų ��Ÿ�� ��ȯ
	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	bool GetAbilityRemainingCooldownByTag(FGameplayTag InCooldownTag,float& TotalCooldownTime, float& RemainingCooldownTime);
	
	// Ȱ ���ؽ� ���� �ӵ� ����
	UFUNCTION(BlueprintCallable)
	virtual void SetBowAimingMaxWalkSpeed(float InMaxWalkSpeed);

private:

	TWeakObjectPtr<AWarriorHeroCharacter> CachedWarriorHeroCharacter;
	TWeakObjectPtr<AWarriorHeroController> CachedWarriorHeroController;
};
