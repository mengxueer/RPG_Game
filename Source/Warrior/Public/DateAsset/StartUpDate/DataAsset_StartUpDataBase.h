// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UWarriorGameplayAbilityBase;
class UWarriorAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual  void GiveToAbilitiesSysComponent(UWarriorAbilitySystemComponent* GAS,int32 Level=1) ;
protected:
	
	//初始化基础能力
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UWarriorGameplayAbilityBase>> ActiveOnGiveAbilities;
	//受击反应能力
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UWarriorGameplayAbilityBase>>  ReactiveAbilities;
    
	
};


