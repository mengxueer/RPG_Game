// xiaoxiao


#include "AbilitySystem/GamePlayAbility/WarriorGameplayAbilityBase.h"

#include "AbilitySystemComponent.h"

void UWarriorGameplayAbilityBase::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo,
                                                const FGameplayAbilitySpec& Spec) {
	Super::OnGiveAbility(ActorInfo, Spec);
	if (ExternAbilityActivePolicy==EExternAbilityActivePolicy::OnGiven) {
		if(!ActorInfo&&Spec.IsActive())return;
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
	}

	
}

void UWarriorGameplayAbilityBase::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled) {
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (ExternAbilityActivePolicy==EExternAbilityActivePolicy::OnGiven) {
		if (ActorInfo) {
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
	
}
