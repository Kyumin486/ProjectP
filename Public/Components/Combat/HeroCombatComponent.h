// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"


class AWarriorHeroWeapon;
/**
 * 
 */
UCLASS()
class PROJECTP_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	AWarriorHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTagToGet)const;

	virtual void OnHitTargetActor(AActor* HitActor)override; // 콜리전 박스에 들어온 적에게 이벤트 태그 전달
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor)override; // 공격 적중 시 잠깐 느려지는 효과 태그 전달

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	AWarriorHeroWeapon* GetHeroCurrentEquippedWeapon()const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	float GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel)const;
};
