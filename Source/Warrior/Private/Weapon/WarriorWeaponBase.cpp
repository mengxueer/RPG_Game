// xiaoxiao


#include "Weapon/WarriorWeaponBase.h"

#include "Components/BoxComponent.h"
#include "Weapon/WarriorHeroWeapon.h"


// Sets default values for this component's properties
AWarriorWeaponBase::AWarriorWeaponBase() {
	

	WarriorWeapon =CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WarriorWeapon"));
	WarriorWeapon->SetupAttachment(GetRootComponent());
	WeaponCollisionBox=CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(WarriorWeapon);
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}



