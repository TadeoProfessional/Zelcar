#include "PotionData.h"
#include "CustomAssetManager.h"


FPrimaryAssetId UPotionData::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(UCustomAssetManager::PotionType, GetFName());
}