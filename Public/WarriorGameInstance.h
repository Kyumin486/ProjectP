// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameplayTagContainer.h"
#include "Engine/StreamableManager.h"

#include "WarriorGameInstance.generated.h"

class UPreLoadDataAsset;
class UUserWidget;


USTRUCT(BlueprintType)
struct FWarriorGameLevelSet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (Categories = "GameData.Level"))
	FGameplayTag LevelTag;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> Level;

	bool IsValid() const
	{
		return LevelTag.IsValid() && !Level.IsNull();
	}

};

/**
 * 
 */
UCLASS()
class PROJECTP_API UWarriorGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init()override;

	void OnPreLoadMap(const FString&);
	void OnDestinationWorldLoaded(UWorld* LoadedWorld);

protected:

	FStreamableManager StreamableManager;

	UPROPERTY(EditAnywhere)
	TArray<UPreLoadDataAsset*> PreLoadDataAssets;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TArray<FWarriorGameLevelSet> GameLevelSets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UUserWidget> LoadingScreenClass;
	
public:
	UFUNCTION(BlueprintPure, meta = (GameplayTagFilter = "GameData.Level"))
	TSoftObjectPtr<UWorld> GetGameLevelByTag(FGameplayTag InTag);

	void OnPreloadAssetsLoaded();
};
