// xiaoxiao


#include "Component/Combat/HeroCombatComponent.h"

#include "Weapon/WarriorHeroWeapon.h"


AWarriorHeroWeapon* UHeroCombatComponent::GetWeaponClassByTag(FGameplayTag Tag)
{
	return Cast<AWarriorHeroWeapon>(GetToWeaponByTag(Tag));
}
