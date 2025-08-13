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

	void GetAvailableActorsToLock(); // Ʈ���̽��� ���� ������ Ÿ�� �迭�� ����
	bool TryLockOnTarget(); // Ʈ���̽� ������ ���� ���� ���� ��ȯ �� ���� ���� �׸���
	AActor* GetNearestTargetFromAvailableActors(const TArray<AActor*>& InAvailableActors); // Ÿ�� �迭���� ���� ����� ���� ��ȯ
	void GetAvailableActorsAroundTarget(TArray<AActor*>& OutActorsOnLeft, TArray<AActor*>& OutActorsOnRight); // Ÿ���� ���� �����ʿ� �ִ� ���͸� �迭�� ��ȯ
	void DrawTargetLockWidget();
	void SetTargetLockWidgetPosition(); // ��ũ���� ǥ��Ǵ� ���� ���� ��ġ ����
	void InitTargetLockMovement(); // ������ �� �÷��̾� ���� �ӵ�
	void InitTargetLockMappingContext(); // ������ �� ����ϴ� ���� ���ؽ�Ʈ ����
	void CleanUp(); // ���� ������ ���� �迭�� Empty
	void CancelTargetLockAbility(); // �����Ƽ ����
	void ResetTargetLockMovement(); // ������ �÷��̾� �ӵ��� ��ȯ
	void ResetTargetLockMappingContext(); // ������ ���� ���ؽ�Ʈ�� ��ȯ

	UFUNCTION(BlueprintCallable)
	void OnTargetLockTick(float DeltaTime); // AbilityTask�� ���� ƽ���� ���� ���缭 ĳ���� ȸ��

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
	TArray<AActor*> AvailableActorsToLock; // �� �� �ִ� ���͵�

	UPROPERTY()
	UWarriorWidgetBase* DrawnTargetLockWidget;

	UPROPERTY()
	FVector2D TargetLockWidgetSize = FVector2D::ZeroVector;

	UFUNCTION(BlueprintCallable)
	void SwitchTarget(const FGameplayTag& InSwitchDirectionTag);

public:

	UPROPERTY(BlueprintReadOnly)
	AActor* CurrentLockedActor; // ���� ���� ����

};
