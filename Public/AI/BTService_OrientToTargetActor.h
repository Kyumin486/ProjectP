// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_OrientToTargetActor.generated.h"

/**
 *
 */
UCLASS()
class PROJECTP_API UBTService_OrientToTargetActor : public UBTService
{
	GENERATED_BODY()

	UBTService_OrientToTargetActor();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	// Begin UBTNode Interface
	virtual void InitializeFromAsset(UBehaviorTree& Asset);
	virtual FString GetStaticDescription() const;
	// End UBTNode Interface

	UPROPERTY(EditAnywhere, Category = "Target")
	FBlackboardKeySelector InTargetActorKey;

	UPROPERTY(EditAnywhere, Category = "Target")
	float RotationInterpSpeed;
};
