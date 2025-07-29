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
	// ĳ���� ���⸦ CharacterCarriedWeaponMap TMap�� �����ϴ� �Լ�
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	void RegisterSpawnedWeapon(FGameplayTag InWaeponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	// ĳ���Ͱ� ������ �ִ� ���⸦ Tag�� ���� �Ű������� ��ġ�ϴ��� Ȯ�� �� ��ȯ
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combet")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet)const;

	// ĳ������ ���� ���⸦ ��ȯ
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
