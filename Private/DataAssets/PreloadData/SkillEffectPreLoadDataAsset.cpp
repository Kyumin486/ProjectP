// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/PreloadData/SkillEffectPreLoadDataAsset.h"
#include "NiagaraSystem.h"

void USkillEffectPreLoadDataAsset::CollectAssetsToPreload(TArray<FSoftObjectPath>& OutAssets) const
{
	for (auto& Effect : SkillEffect)
	{
		OutAssets.Add(Effect.ToSoftObjectPath());

		FSoftObjectPath AssetPath(Effect->GetPathName());
		// 경로 이름 출력 (로그에 찍기)
		UE_LOG(LogTemp, Warning, TEXT("Preloading asset path: %s"), *AssetPath.ToString());
	}

}
