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


	// 1. 소프트 경로 배열 준비
	TArray<FSoftObjectPath> AssetsToLoad;
	for (UPreLoadDataAsset* DataAsset : PreLoadDataAssets)
	{
		if (DataAsset)
		{
			// 데이터 에셋 내부 파일 모으기
			DataAsset->CollectAssetsToPreload(AssetsToLoad);
			// DataAsset 객체의 경로를 소프트 오브젝트 패스로 변환
			AssetsToLoad.Add(FSoftObjectPath(DataAsset->GetPathName()));

		}
	}
	
	// 2. 비동기 로드 요청, 완료 시 콜백 실행
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
	//LoadingScreenAttributes.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget(); 언리얼 테스트용 로딩화면
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
