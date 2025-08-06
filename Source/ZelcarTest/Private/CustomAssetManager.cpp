#include "CustomAssetManager.h"
#include "WeaponData.h"
#include "ResourceData.h"
#include "PotionData.h"

UCustomAssetManager& UCustomAssetManager::Get()
{
	return static_cast<UCustomAssetManager&>(UAssetManager::Get());
}

void UCustomAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	ScanPathIfPossible(UCustomAssetManager::PotionType, PotionsPath, UPotionData::StaticClass());
	ScanPathIfPossible(UCustomAssetManager::ResourceType, ResourcesPath, UResourceData::StaticClass());
	ScanPathIfPossible(UCustomAssetManager::WeaponType, WeaponsPath, UWeaponData::StaticClass());
}

void UCustomAssetManager::ScanPathIfPossible(FPrimaryAssetType AssetType, const FString& Path, TSubclassOf<UObject> AssetClass)
{
	if (!Path.IsEmpty())
	{
		ScanPathForPrimaryAssets(AssetType, Path, AssetClass, false);
	}
}

void UCustomAssetManager::LoadPotionAssets(FPotionDataLoadCompleteDelegate OnCompletedDelegate)
{
    TArray<FAssetData> PotionAssetsData;
    GetPrimaryAssetDataList(UCustomAssetManager::PotionType, PotionAssetsData);

    TArray<FPrimaryAssetId> PotionAssetIdsToLoad;
    for (const FAssetData& PotionAssetData : PotionAssetsData)
    {
        PotionAssetIdsToLoad.Add(PotionAssetData.GetPrimaryAssetId());
    }
}

void UCustomAssetManager::LoadResourceAssets(FResourceDataLoadCompleteDelegate OnCompletedDelegate)
{
    TArray<FAssetData> ResourceAssetsData;
    GetPrimaryAssetDataList(UCustomAssetManager::ResourceType, ResourceAssetsData);

    TArray<FPrimaryAssetId> ResourceAssetIdsToLoad;
    for (const FAssetData& ResourceAssetData : ResourceAssetsData)
    {
        ResourceAssetIdsToLoad.Add(ResourceAssetData.GetPrimaryAssetId());
    }
}

void UCustomAssetManager::LoadWeaponAssets(FWeaponDataLoadCompleteDelegate OnCompletedDelegate)
{
 	TArray<FAssetData> WeaponAssetsData;
 	GetPrimaryAssetDataList(UCustomAssetManager::WeaponType, WeaponAssetsData);

 	TArray<FPrimaryAssetId> WeaponAssetIdsToLoad;
 	for (const FAssetData& WeaponAssetData : WeaponAssetsData)
 	{
 		WeaponAssetIdsToLoad.Add(WeaponAssetData.GetPrimaryAssetId());
 	}

 	FStreamableDelegate OnLoadCompleted = FStreamableDelegate::CreateLambda([WeaponAssetIdsToLoad]()
 		{
            // TArray<UWeaponData*> WeaponAssets;
            // for (const FPrimaryAssetId& WeaponAssetId : WeaponAssetIdsToLoad)
            // {
            //	WeaponAssets.Add(GetPrimaryAssetObject<UWeaponData>(WeaponAssetId))
            // }
			// OnCompletedDelegate.Broadcast(WeaponAssets);
 		});

 	LoadPrimaryAssets(WeaponAssetIdsToLoad, {}/*Vacio porque no importa por ahora*/, OnLoadCompleted);

// 	// Alternativa mas directa, skipea la carga de metadatos y directamente carga los assets por tipo
// 	// LoadPrimaryAssetsWithType(WeaponDataAssetType, {}, OnLoadCompleted)
}
