// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Component/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;

/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
public:
	//从标签组测装备武器的技能
	UFUNCTION(BlueprintCallable)
	void RegisterTagToWeapon(FGameplayTag Tag,AWarriorWeaponBase* Weapon,bool bIsRegister=false);
	//获取装备武器的技能
	UFUNCTION(BlueprintCallable)
	AWarriorWeaponBase* GetToWeaponByTag(const FGameplayTag &Tag)const;
	
	UPROPERTY(BlueprintReadWrite)
	FGameplayTag CurrentTag;
	
	UFUNCTION(BlueprintCallable)
	AWarriorWeaponBase* GetCurrentEquippedWeaponTag()const;
	
private:

	TMap<FGameplayTag,TObjectPtr<AWarriorWeaponBase>>  AbilityManager;
	
};
