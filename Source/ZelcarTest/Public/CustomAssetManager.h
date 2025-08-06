#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "WeaponData.h"
#include "ResourceData.h"
#include "PotionData.h"
#include "CustomAssetManager.generated.h"

DECLARE_DELEGATE_OneParam(FPotionDataLoadCompleteDelegate, TArray<UPotionData*>);
DECLARE_DELEGATE_OneParam(FResourceDataLoadCompleteDelegate, TArray<UResourceData*>);
DECLARE_DELEGATE_OneParam(FWeaponDataLoadCompleteDelegate, TArray<UWeaponData*>);

UCLASS(Config = Game)
class ZELCARTEST_API UCustomAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UCustomAssetManager& Get();
	static inline FPrimaryAssetType PotionType = FName(TEXT("PotionData"));
	static inline FPrimaryAssetType ResourceType = FName(TEXT("ResourceData"));
	static inline FPrimaryAssetType WeaponType = FName(TEXT("WeaponData"));

	virtual void StartInitialLoading() override;

	void LoadPotionAssets(FPotionDataLoadCompleteDelegate OnCompletedDelegate);
	void LoadResourceAssets(FResourceDataLoadCompleteDelegate OnCompletedDelegate);
	void LoadWeaponAssets(FWeaponDataLoadCompleteDelegate OnCompletedDelegate);

protected:
	UPROPERTY(Config)
	FString PotionsPath = "/ZelcarTest/ZelcarTest/Data/Potions";
	FString ResourcesPath = "/ZelcarTest/ZelcarTest/Data/Resources";
	FString WeaponsPath = "/ZelcarTest/ZelcarTest/Data/Weapons";

private:
	void ScanPathIfPossible(FPrimaryAssetType AssetType, const FString& Path, TSubclassOf<UObject> AssetClass);
};
