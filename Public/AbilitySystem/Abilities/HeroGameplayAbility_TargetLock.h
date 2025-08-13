// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "HeroGameplayAbility_TargetLock.generated.h"


class UWarriorWidgetBase;
class UInputMappingContext;
struct FGameplayTag;
/**
 *
 */
UCLASS()
class PROJECTP_API UHeroGameplayAbility_TargetLock : public UWarriorHeroGameplayAbility
{
	GENERATED_BODY()


protected:

	//~ Begin UGameplayAbility Interface
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)override;
	//~ End UGameplayAbility Interface

private:

	void GetAvailableActorsToLock(); // 트레이스로 락온 가능한 타겟 배열에 저장
	bool TryLockOnTarget(); // 트레이스 가능한 액터 존재 유무 반환 및 락온 위젯 그리기
	AActor* GetNearestTargetFromAvailableActors(const TArray<AActor*>& InAvailableActors); // 타겟 배열에서 가장 가까운 액터 반환
	void GetAvailableActorsAroundTarget(TArray<AActor*>& OutActorsOnLeft, TArray<AActor*>& OutActorsOnRight); // 타겟의 왼쪽 오른쪽에 있는 액터를 배열로 반환
	void DrawTargetLockWidget();
	void SetTargetLockWidgetPosition(); // 스크린에 표기되는 락온 위젯 위치 조절
	void InitTargetLockMovement(); // 락온할 때 플레이어 걸음 속도
	void InitTargetLockMappingContext(); // 락온할 때 사용하는 맵핑 컨텍스트 설정
	void CleanUp(); // 락온 가능한 액터 배열을 Empty
	void CancelTargetLockAbility(); // 어빌리티 종료
	void ResetTargetLockMovement(); // 기존의 플레이어 속도로 전환
	void ResetTargetLockMappingContext(); // 기존의 맵핑 컨텍스트로 전환

	UFUNCTION(BlueprintCallable)
	void OnTargetLockTick(float DeltaTime); // AbilityTask를 통해 틱마다 적에 맞춰서 캐릭터 회전

	float CachedDefaultMaxWalkSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	float TargetLockCameraOffsetDistance = 20.f;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	float TargetLockMaxWalkSpeed = 200;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	float BoxTraceDistance = 5000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	FVector TraceBoxSize = FVector(5000.f, 5000.f, 300.f);

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	TArray< TEnumAsByte < EObjectTypeQuery > > BoxTraceChannel;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	bool bShowPersistentDebugShape = false;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	TSubclassOf<UWarriorWidgetBase> TargetLockWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	float TargetLockRotationInterpSpeed = 5.f;

	UPROPERTY(EditDefaultsOnly, Category = "Target Lock")
	UInputMappingContext* TargetLockMappingContext;

	UPROPERTY()
	TArray<AActor*> AvailableActorsToLock; // 볼 수 있는 액터들

	UPROPERTY()
	UWarriorWidgetBase* DrawnTargetLockWidget;

	UPROPERTY()
	FVector2D TargetLockWidgetSize = FVector2D::ZeroVector;

	UFUNCTION(BlueprintCallable)
	void SwitchTarget(const FGameplayTag& InSwitchDirectionTag);

public:

	UPROPERTY(BlueprintReadOnly)
	AActor* CurrentLockedActor; // 지금 보는 액터

};
