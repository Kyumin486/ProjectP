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

	virtual void OnHitTargetActor(AActor* HitActor)override;
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor)override;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	AWarriorHeroWeapon* GetHeroCurrentEquippedWeapon()const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	float GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel)const;
};
