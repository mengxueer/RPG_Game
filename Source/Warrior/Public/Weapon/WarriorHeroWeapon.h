// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "WarriorWeaponBase.h"
#include "WarriorStruct/WarriorStructTypes.h"
#include "WarriorHeroWeapon.generated.h"




UCLASS()
class WARRIOR_API AWarriorHeroWeapon : public AWarriorWeaponBase {
	GENERATED_BODY()

public:

	AWarriorHeroWeapon();

protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="weapon")
	FWarriorHeroWeaponData WeaponDate;
};
