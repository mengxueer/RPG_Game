// xiaoxiao


#include "DateAsset/StartUpDate/DataAsset_StartUpDataBase.h"

#include "WarriorDebugHelp.h"
#include "AbilitySystem/GamePlayAbility/WarriorGameplayAbilityBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"


void UDataAsset_StartUpDataBase::GiveToAbilitiesSysComponent(UWarriorAbilitySystemComponent* GAS, int32 Level)
{
	if (GAS!=nullptr)
	{
		for (const TSubclassOf<UWarriorGameplayAbilityBase>& Ablity : ActiveOnGiveAbilities)
		{
			FGameplayAbilitySpec AbilitySpec(Ablity);
			AbilitySpec.SourceObject=GAS->GetAvatarActor();
			AbilitySpec.Level=Level;
			GAS->GiveAbility(AbilitySpec);
		}
		
		for (const TSubclassOf<UWarriorGameplayAbilityBase>& Ablity : ReactiveAbilities)
		{
			FGameplayAbilitySpec AbilitySpec(Ablity);
			AbilitySpec.SourceObject=GAS->GetAvatarActor();
			AbilitySpec.Level=Level;
			GAS->GiveAbility(AbilitySpec);
		}
	}
	else
	{
		Debug::print("GAS 没有获取到在StaUpData___31行");
	}
}
