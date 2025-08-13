// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/PreloadData/PreLoadDataAsset.h"
#include "SoundPreLoadDataAsset.generated.h"

class USoundBase;
/**
 * 
 */
UCLASS()
class PROJECTP_API USoundPreLoadDataAsset : public UPreLoadDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<USoundBase>> SoundBase;
	virtual void CollectAssetsToPreload(TArray<FSoftObjectPath>& OutAssets) const override;
};
