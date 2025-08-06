#include "ResourceData.h"
#include "CustomAssetManager.h"


FPrimaryAssetId UResourceData::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(UCustomAssetManager::ResourceType, GetFName());
}