// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PreLoadDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTP_API UPreLoadDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	// 프리로드할 에셋 경로를 모아서 반환함
	virtual void CollectAssetsToPreload(TArray<FSoftObjectPath>& OutAssets) const {}
};
