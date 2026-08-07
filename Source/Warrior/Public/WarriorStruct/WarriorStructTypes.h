// xiaoxiao

#pragma once
#include "GameplayTagContainer.h"

#include "WarriorStructTypes.generated.h"

class UWarriorGameplayAbilityBase;
class UInputMappingContext;
class UWarriorHeroLinkedAnimLayer;
USTRUCT(BlueprintType)
struct FWarriorHeroAbility
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorGameplayAbilityBase> GameplayAbility;

	bool IsValid() const;
};
USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponLinkedAnimLayer;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UInputMappingContext> InputContext;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TArray<FWarriorHeroAbility> WarriorAbility;
	
	
};