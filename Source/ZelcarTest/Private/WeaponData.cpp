#include "WeaponData.h"
#include "CustomAssetManager.h"


FPrimaryAssetId UWeaponData::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(UCustomAssetManager::WeaponType, GetFName());
}