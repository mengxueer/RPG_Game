// xiaoxiao


#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/GamePlayAbility/WarriorGameplayAbilityBase.h"
#include "WarriorStruct/WarriorStructTypes.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InputTag) {
	if (InputTag.IsValid()) {
		for (const FGameplayAbilitySpec& SpecElement : GetActivatableAbilities()) {
			if (SpecElement.DynamicAbilityTags.HasTagExact(InputTag)) {
				TryActivateAbility(SpecElement.Handle);
			}
		}
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InputTag) {
}

void UWarriorAbilitySystemComponent::GiveHeroAbility(const TArray<FWarriorHeroAbility>& Ability,int32 Level) {
	if (Ability.IsEmpty()) return;
		for (const FWarriorHeroAbility& Element : Ability) {
			if (!Element.IsValid()) continue;
		     FGameplayAbilitySpec AbilitySpec(Element.GameplayAbility);
			AbilitySpec.DynamicAbilityTags.AddTag(Element.InputTag);
			AbilitySpec.Level=Level;
			AbilitySpec.SourceObject=GetAvatarActor();
			GiveAbility(AbilitySpec);
			

		}

}
