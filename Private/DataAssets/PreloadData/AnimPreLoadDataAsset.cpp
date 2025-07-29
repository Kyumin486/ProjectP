// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/PreloadData/AnimPreLoadDataAsset.h"

void UAnimPreLoadDataAsset::CollectAssetsToPreload(TArray<FSoftObjectPath>& OutAssets) const
{
	for (auto& AnimSeq : AnimSequences)
	{
		OutAssets.Add(AnimSeq.ToSoftObjectPath());

		FSoftObjectPath AssetPath(AnimSeq->GetPathName());
		// 경로 이름 출력 (로그에 찍기)
		UE_LOG(LogTemp, Warning, TEXT("Preloading asset path: %s"), *AssetPath.ToString());
	}
	for (auto& Montage : AnimMontages)
	{
		OutAssets.Add(Montage.ToSoftObjectPath());

		FSoftObjectPath AssetPath(Montage->GetPathName());
		// 경로 이름 출력 (로그에 찍기)
		UE_LOG(LogTemp, Warning, TEXT("Preloading asset path: %s"), *AssetPath.ToString());
	}
}
