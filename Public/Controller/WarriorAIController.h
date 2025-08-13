// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "WarriorAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;

/**
 * 
 */
UCLASS()
class PROJECTP_API AWarriorAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	AWarriorAIController(const FObjectInitializer& ObjectInitializer);
	//~ Begin IGenericTeamAgentInterface Interface.
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override; // 감지된 적과의 Team ID 비교
	//~ Begin IGenericTeamAgentInterface Interface.

protected:

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	UAIPerceptionComponent* EnemyPerceptionComponent;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	UAISenseConfig_Sight* AISenseConfig_Sight;

	UFUNCTION()
	virtual void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config")
	bool bEnableDetourCrowdAvoidance=true;
	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config", meta = (EditCondition = "bEnableDetourCrowdAvoidance", UIMin = "1", UIMax = "4"))
	int32 DetourCrowdAvoidanceQuality = 4;
	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config",meta = (EditCondition = "bEnableDetourCrowdAvoidance"))
	float CollisionQueryRange = 600.f;
};

