#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/AssetManager.h"
#include "ItemData.h"
#include "WeaponData.generated.h"

UCLASS(BlueprintType)
class ZELCARTEST_API UWeaponData : public UItemData
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
