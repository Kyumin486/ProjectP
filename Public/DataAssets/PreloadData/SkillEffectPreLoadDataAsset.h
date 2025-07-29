// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/PreloadData/PreLoadDataAsset.h"
#include "SkillEffectPreLoadDataAsset.generated.h"


class UNiagaraSystem;
/**
 * 
 */
UCLASS()
class PROJECTP_API USkillEffectPreLoadDataAsset : public UPreLoadDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<UNiagaraSystem>> SkillEffect;

	virtual void CollectAssetsToPreload(TArray<FSoftObjectPath>& OutAssets) const override;
};
