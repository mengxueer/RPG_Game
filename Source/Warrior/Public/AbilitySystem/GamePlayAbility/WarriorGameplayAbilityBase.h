// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WarriorGameplayAbilityBase.generated.h"

class UWarriorAbilitySystemComponent;
class UHeroCombatComponent;

UENUM()
enum class EExternAbilityActivePolicy:uint8
{
	OnGiven,
	OnTriggered
};

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual  void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	
protected:
	UPROPERTY(EditDefaultsOnly)
	EExternAbilityActivePolicy ExternAbilityActivePolicy=EExternAbilityActivePolicy::OnTriggered;
	
	UFUNCTION(BlueprintPure)
	UHeroCombatComponent* GetPawnCombatComponentFromActorInfo() const;
	
	UFUNCTION(BlueprintPure)
	UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponentFromActorInfo() const;
};
