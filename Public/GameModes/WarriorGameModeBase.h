// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WarriorEnumTypes.h"

#include "WarriorGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTP_API AWarriorGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly)
	int EnemyCount = 0;

	UPROPERTY(BlueprintReadWrite)
	EWarriorBGM WarriorBGM;
};
