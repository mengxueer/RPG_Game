// xiaoxiao


#include "AbilitySystem/GamePlayAbility/WarriorHeroGameplayAbility.h"

#include "Characters/WarriorHeroCharacter.h"
#include "playerController/WarriorHeroPlayerController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetWarriorHeroCharacterFromActorInfo()  {
	if (!WarriorHeroCharacter.IsValid())
	{
		WarriorHeroCharacter = Cast<AWarriorHeroCharacter>(GetAvatarActorFromActorInfo());
	}
	return WarriorHeroCharacter.Get();
}

AWarriorHeroPlayerController* UWarriorHeroGameplayAbility::GetWarriorHeroPlayerControllerFromActorInfo()  {
	if (!WarriorHeroPlayerController.IsValid())
	{
		WarriorHeroPlayerController = Cast<AWarriorHeroPlayerController>((GetActorInfo().PlayerController));
	}
	return WarriorHeroPlayerController.Get();
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()  {
	return GetWarriorHeroCharacterFromActorInfo()->GetCombatComponent();
}

