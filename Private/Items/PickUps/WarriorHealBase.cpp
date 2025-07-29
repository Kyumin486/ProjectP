// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/PickUps/WarriorHealBase.h"
#include "Characters/WarriorHeroCharacter.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "WarriorGameplayTags.h"
#include "GameplayEffect.h"

void AWarriorHealBase::OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AWarriorHeroCharacter* OverlappedHeroCharacter = Cast<AWarriorHeroCharacter>(OtherActor))
	{
		OverlappedHeroCharacter->GetWarriorAbilitySystemComponent()->TryActivateAbilityByTag(WarriorGameplayTags::Player_Ability_PickUp_Heal);

	}
}

void AWarriorHealBase::OnPickUpCollisionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AWarriorHealBase::Consume(UWarriorAbilitySystemComponent* AbilitySystemComponent, int32 ApplyLevel)
{
	AbilitySystemComponent->ApplyGameplayEffectToSelf(HealGameplayEffectClass->GetDefaultObject<UGameplayEffect>(),ApplyLevel,AbilitySystemComponent->MakeEffectContext());
	BP_OnHealConsumed();
}


