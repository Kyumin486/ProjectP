// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/PreloadData/SoundPreLoadDataAsset.h"
#include "Sound/SoundBase.h"

void USoundPreLoadDataAsset::CollectAssetsToPreload(TArray<FSoftObjectPath>& OutAssets) const
{
	for (auto& Sound : SoundBase)
	{
		OutAssets.Add(Sound.ToSoftObjectPath());

		FSoftObjectPath AssetPath(Sound->GetPathName());
		// ��� �̸� ��� (�α׿� ���)
		UE_LOG(LogTemp, Warning, TEXT("Preloading asset path: %s"), *AssetPath.ToString());
	}
	
}
