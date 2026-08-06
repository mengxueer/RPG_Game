// xiaoxiao


#include "AbilitySystem/WarriorAbilitySystemComponent.h"

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
