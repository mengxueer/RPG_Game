// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DateAsset/StartUpDate/DataAsset_StartUpDataBase.h"
#include "DataAsset_HeroStartUpData.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct FWarriorHeroAbility
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag InputTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)	
	TSubclassOf<UWarriorGameplayAbilityBase> GameplayAbility;
	
	bool IsValid()const;
	
};
UCLASS()
class WARRIOR_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitiesSysComponent(UWarriorAbilitySystemComponent* GAS, int32 Level = 1) override;
private:
	UPROPERTY(EditDefaultsOnly)
	TArray<FWarriorHeroAbility> HeroStartIpAbilitySets;
};
