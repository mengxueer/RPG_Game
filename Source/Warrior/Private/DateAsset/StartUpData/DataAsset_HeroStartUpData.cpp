// xiaoxiao


#include "DateAsset/StartUpDate/DataAsset_HeroStartUpData.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/GamePlayAbility/WarriorGameplayAbilityBase.h"
#include "WarriorStruct/WarriorStructTypes.h"


void UDataAsset_HeroStartUpData::GiveToAbilitiesSysComponent(UWarriorAbilitySystemComponent* GAS, int32 Level)
{
	Super::GiveToAbilitiesSysComponent(GAS, Level);
	for (const FWarriorHeroAbility& AbilityElement : HeroStartIpAbilitySets)
	{
		if (!AbilityElement.IsValid()) continue;
		FGameplayAbilitySpec AbilitySpec(AbilityElement.GameplayAbility);
		AbilitySpec.Level=Level;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilityElement.InputTag);
		AbilitySpec.SourceObject=GAS->GetAvatarActor();
		GAS->GiveAbility(AbilitySpec);
	}
}
