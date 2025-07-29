// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/WarriorAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "WarriorFunctionLibrary.h"
#include "WarriorGameplayTags.h"
#include "Components/UI/PawnUIComponent.h"
#include "Interfaces/PawnUIInterface.h"
#include "Components/UI/HeroUIComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "WarriorDebugHelper.h"

UWarriorAttributeSet::UWarriorAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
	InitBaseWalkSpeed(300.f);
	InitWalkSpeedMultiplier(1.f);
	InitCurrentWalkSpeed(300.f);
	InitStatPoint(0.f);
	InitMaxExp(1.f);
	InitCurrentExp(0.f);
	InitRewardExp(1.f);
	InitCurrentLevel(1.f);



}

void UWarriorAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{

	// 이동 속도 슬로우 효과
	if (Attribute == GetWalkSpeedMultiplierAttribute())
	{
		APawn* TargetPawn = Cast<APawn>(GetOwningActor());
		if (TargetPawn)
		{
			UCharacterMovementComponent* TargetPawnMovement = Cast<UCharacterMovementComponent>(TargetPawn->GetMovementComponent());
			if (TargetPawnMovement)
			{

				TargetPawnMovement->MaxWalkSpeed = GetBaseWalkSpeed() * NewValue;
				SetCurrentWalkSpeed(TargetPawnMovement->MaxWalkSpeed);

				if (GEngine)
				{
					/*GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("NewValue Set To: %.1f"), NewValue));
					GEngine->AddOnScreenDebugMessage(2, 5.f, FColor::Green, FString::Printf(TEXT("Speed Set To: %.1f"), TargetPawnMovement->MaxWalkSpeed));
					GEngine->AddOnScreenDebugMessage(3, 5.f, FColor::Green, FString::Printf(TEXT("CurrentWalkSpeed Set To: %.1f"), GetCurrentWalkSpeed()));*/
				}
			}
		}
	}
}



void UWarriorAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	// 레벨 업
	while (GetCurrentExp() >= GetMaxExp())
	{
		if (GetCurrentExp() > GetMaxExp())
		{
			SetCurrentExp(GetCurrentExp() - GetMaxExp());
		}
		else
		{
			SetCurrentExp(0);
		}
		SetStatPoint(GetStatPoint() + 1);
		SetMaxExp(GetMaxExp() + 2);

		SetCurrentLevel(GetCurrentLevel() + 1);

		// 레벨 업 하고 현재 레벨 전달
		OnLevelUpDelegate.Broadcast(GetCurrentLevel());
		//	Debug::Print(TEXT("Level Up!!!"));
	}



	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Cast<IPawnUIInterface>(Data.Target.GetAvatarActor()));
	}

	check(CachedPawnUIInterface.IsValid());

	UPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();

	check(PawnUIComponent);

	// 체력 설정
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		// 현재 체력 퍼센트를 브로드캐스트
		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
	}


	// 분노 설정
	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());

		SetCurrentRage(NewCurrentRage);

		// 분노 게이지 확인 후 태그 설정
		if (GetCurrentRage() == GetMaxRage())
		{
			UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), WarriorGameplayTags::Player_Status_Rage_Full);
		}
		else if (GetCurrentRage() == 0.f)
		{
			UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), WarriorGameplayTags::Player_Status_Rage_None);
		}
		else
		{
			UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(Data.Target.GetAvatarActor(), WarriorGameplayTags::Player_Status_Rage_Full);
			UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(Data.Target.GetAvatarActor(), WarriorGameplayTags::Player_Status_Rage_None);
		}

		// 현재 분노 퍼센트를 브로드캐스트
		if (UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
		{
			HeroUIComponent->OnCurrentRageChanged.Broadcast(GetCurrentRage() / GetMaxRage());
		}
	}

	// 데미지 설정
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);

		/*	const FString DebugString = FString::Printf(TEXT("OldHealth : %f, DamageDone : %f, NewHealth : %f"), OldHealth, DamageDone, NewCurrentHealth);

			Debug::Print(DebugString, FColor::Green);*/

			// 현재 체력 퍼센트를 브로드캐스트
		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());

		if (NewCurrentHealth == 0)
		{
			UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), WarriorGameplayTags::Shared_Status_Dead);

		}

	}
}



