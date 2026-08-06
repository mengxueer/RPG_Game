// xiaoxiao


#include "Component/Combat/PawnCombatComponent.h"

 #include "AbilitySystem/GamePlayAbility/WarriorGameplayAbilityBase.h"

void UPawnCombatComponent::RegisterTagToWeapon(FGameplayTag Tag, AWarriorWeaponBase* Weapon,
                                                      bool bIsRegister)  {
	if (bIsRegister) {
		CurrentTag=Tag;
	}
	if (Tag.IsValid()&&Weapon) {
			
		AbilityManager.Emplace(Tag,Weapon);
	}
	
}

AWarriorWeaponBase* UPawnCombatComponent::GetToWeaponByTag(const FGameplayTag &Tag)const {
	return AbilityManager.FindRef(Tag);
}

AWarriorWeaponBase* UPawnCombatComponent::GetCurrentEquippedWeaponTag() const {
		return GetToWeaponByTag(CurrentTag);
}
