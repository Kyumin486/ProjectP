// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/UI/PawnUIComponent.h"
#include "EnemyUIComponent.generated.h"


class UWarriorWidgetBase;
/**
 * 
 */
UCLASS()
class PROJECTP_API UEnemyUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable)
	void RegisterEnemyDrawnWidget(UWarriorWidgetBase* InWidgetToRegister); // 보스 체력바 등록

	UFUNCTION(BlueprintCallable)
	void RemoveEnemyDrawnWidgetsIfAny(); // 보스 사망 시 등록된 보스 체력바 화면에서 삭제

private:

	TArray<UWarriorWidgetBase*> EnemyDrawnWidgets;
};
