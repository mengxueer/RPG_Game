// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WarriorAbilitySystemComponent.generated.h"

struct FWarriorHeroAbility;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void OnAbilityInputPressed(const FGameplayTag&  InputTag);
	void OnAbilityInputReleased(const FGameplayTag&  InputTag);
	
	UFUNCTION(BlueprintCallable)
	void GiveHeroAbility(const TArray<FWarriorHeroAbility>& Ability,int32 Level);
};
