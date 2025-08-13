// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "WarriorAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelUpDelegate,float,NewLevel);



class IPawnUIInterface;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 *
 */
UCLASS()
class PROJECTP_API UWarriorAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:

	UWarriorAttributeSet();

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FLevelUpDelegate OnLevelUpDelegate;

public:

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)override;;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;

	UFUNCTION(BlueprintCallable)
	void AddStatPoint();

	UPROPERTY(BlueprintReadOnly, Category = "CurrentLevel")
	FGameplayAttributeData CurrentLevel;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentLevel)

	UPROPERTY(BlueprintReadOnly, Category = "StatPoint")
	FGameplayAttributeData StatPoint;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, StatPoint)

	UPROPERTY(BlueprintReadOnly, Category = "RewardExp")
	FGameplayAttributeData RewardExp;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, RewardExp)

	UPROPERTY(BlueprintReadOnly, Category = "MaxExp")
	FGameplayAttributeData MaxExp;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxExp)

	UPROPERTY(BlueprintReadOnly, Category = "CurrentExp")
	FGameplayAttributeData CurrentExp;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentExp)

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentHealth)

		UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxHealth)

		UPROPERTY(BlueprintReadOnly, Category = "Rage")
	FGameplayAttributeData CurrentRage;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentRage)

		UPROPERTY(BlueprintReadOnly, Category = "Rage")
	FGameplayAttributeData MaxRage;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxRage)

		UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, AttackPower)

		UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, DefensePower)

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FGameplayAttributeData BaseWalkSpeed;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, BaseWalkSpeed)

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FGameplayAttributeData CurrentWalkSpeed;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentWalkSpeed)

		UPROPERTY(BlueprintReadOnly, Category = "WalkSpeedMultiplier")
	FGameplayAttributeData WalkSpeedMultiplier;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, WalkSpeedMultiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, DamageTaken)



private:
	TWeakInterfacePtr<IPawnUIInterface> CachedPawnUIInterface;
};
