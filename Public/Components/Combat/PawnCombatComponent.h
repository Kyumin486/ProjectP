// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand,
};

/**
 *
 */
UCLASS()
class PROJECTP_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()


public:
	// 캐릭터 무기를 CharacterCarriedWeaponMap TMap에 저장하는 함수
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	void RegisterSpawnedWeapon(FGameplayTag InWaeponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	// 캐릭터가 가지고 있는 무기를 Tag를 통해 매개변수와 일치하는지 확인 후 반환
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet)const;

	// 캐릭터의 현재 무기를 반환
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon()const;

	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combet")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor);

	TArray<AActor*> OverlappedActors;


protected:
	virtual void ToggleCurrentEquippedWeaponCollision(bool bShouldEnable);
	virtual void ToggleBodyCollisionBoxColision(bool bShouldEnable,EToggleDamageType ToggleDamageType);

private:
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponMap;

};
