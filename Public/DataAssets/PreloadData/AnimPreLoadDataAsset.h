// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/PreloadData/PreLoadDataAsset.h"
#include "AnimPreLoadDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTP_API UAnimPreLoadDataAsset : public UPreLoadDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<UAnimSequence>> AnimSequences;
	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<UAnimMontage>> AnimMontages;
	virtual void CollectAssetsToPreload(TArray<FSoftObjectPath>& OutAssets) const override;
};
