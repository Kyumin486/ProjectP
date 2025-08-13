// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorGameInstance.h"
#include "MoviePlayer.h"
#include "Blueprint/UserWidget.h"
#include "DataAssets/PreloadData/PreLoadDataAsset.h"
#include "WarriorDebugHelper.h"
#include "UObject/SoftObjectPath.h"
#include "Engine/AssetManager.h"

void UWarriorGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &ThisClass::OnPreLoadMap);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ThisClass::OnDestinationWorldLoaded);


	// 1. ����Ʈ ��� �迭 �غ�
	TArray<FSoftObjectPath> AssetsToLoad;
	for (UPreLoadDataAsset* DataAsset : PreLoadDataAssets)
	{
		if (DataAsset)
		{
			// ������ ���� ���� ���� ������
			DataAsset->CollectAssetsToPreload(AssetsToLoad);
			// DataAsset ��ü�� ��θ� ����Ʈ ������Ʈ �н��� ��ȯ
			AssetsToLoad.Add(FSoftObjectPath(DataAsset->GetPathName()));

		}
	}
	
	// 2. �񵿱� �ε� ��û, �Ϸ� �� �ݹ� ����
	StreamableManager.RequestAsyncLoad
	(
		AssetsToLoad,
		FStreamableDelegate::CreateUObject(this, &UWarriorGameInstance::OnPreloadAssetsLoaded)
	);

}

void UWarriorGameInstance::OnPreLoadMap(const FString&)
{

	FLoadingScreenAttributes LoadingScreenAttributes;
	LoadingScreenAttributes.bAutoCompleteWhenLoadingCompletes = true;
	LoadingScreenAttributes.MinimumLoadingScreenDisplayTime = 5.f;
	//LoadingScreenAttributes.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget(); �𸮾� �׽�Ʈ�� �ε�ȭ��
	LoadingScreenAttributes.WidgetLoadingScreen = CreateWidget(this, LoadingScreenClass)->TakeWidget();

	GetMoviePlayer()->SetupLoadingScreen(LoadingScreenAttributes);
}

void UWarriorGameInstance::OnDestinationWorldLoaded(UWorld* LoadedWorld)
{
	GetMoviePlayer()->StopMovie();
}

TSoftObjectPtr<UWorld> UWarriorGameInstance::GetGameLevelByTag(FGameplayTag InTag)
{
	for (const FWarriorGameLevelSet& GameLevelSet : GameLevelSets)
	{
		if (!GameLevelSet.IsValid()) continue;

		if (GameLevelSet.LevelTag == InTag)
		{
			return GameLevelSet.Level;
		}
	}

	return TSoftObjectPtr<UWorld>();
}

void UWarriorGameInstance::OnPreloadAssetsLoaded()
{
	//Debug::Print(TEXT("Preload Data Assets loaded!"));
	UE_LOG(LogTemp, Warning, TEXT("Preload Data Assets loaded!"));
}
