#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.h"
#include "PotionData.generated.h"

UCLASS(BlueprintType)
class ZELCARTEST_API UPotionData : public UItemData
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};