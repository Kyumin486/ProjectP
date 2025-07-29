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
	// �����ε��� ���� ��θ� ��Ƽ� ��ȯ��
	virtual void CollectAssetsToPreload(TArray<FSoftObjectPath>& OutAssets) const {}
};
