#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.generated.h"

/**
* Deberia ser una clase abstracta
*/
UCLASS()
class ZELCARTEST_API UItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;
};
