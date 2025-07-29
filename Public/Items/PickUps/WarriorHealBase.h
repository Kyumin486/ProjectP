// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PickUps/WarriorPickUpBase.h"
#include "WarriorHealBase.generated.h"

class UGameplayEffect;
class UWarriorAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class PROJECTP_API AWarriorHealBase : public AWarriorPickUpBase
{
	GENERATED_BODY()
	
public:
	virtual void OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)override;
	virtual void OnPickUpCollisionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)override;

	void Consume(UWarriorAbilitySystemComponent* AbilitySystemComponent, int32 ApplyLevel);

	UFUNCTION(BlueprintImplementableEvent,meta = (DisplayName = "On Heal Consumed"))
	void BP_OnHealConsumed();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> HealGameplayEffectClass;
};
