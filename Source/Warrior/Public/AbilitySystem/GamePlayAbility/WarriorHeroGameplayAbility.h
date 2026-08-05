// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GamePlayAbility/WarriorGameplayAbilityBase.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AWarriorHeroPlayerController;
class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbilityBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure)
	AWarriorHeroCharacter* GetWarriorHeroCharacterFromActorInfo() ;
	UFUNCTION(BlueprintPure)
	AWarriorHeroPlayerController* GetWarriorHeroPlayerControllerFromActorInfo() ;
	UFUNCTION(BlueprintPure)
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo() ;

protected:
	TWeakObjectPtr<AWarriorHeroCharacter> WarriorHeroCharacter;
	TWeakObjectPtr<AWarriorHeroPlayerController> WarriorHeroPlayerController;
};
