// xiaoxiao


#include "WarriorStruct/WarriorStructTypes.h"

#include "AbilitySystem/GamePlayAbility/WarriorGameplayAbilityBase.h"

bool FWarriorHeroAbility::IsValid() const {
	return InputTag.IsValid()&&GameplayAbility;
}
