// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "WarriorWeaponBase.generated.h"


class UBoxComponent;

UCLASS()
class WARRIOR_API AWarriorWeaponBase : public AActor {
	GENERATED_BODY()

public:

	AWarriorWeaponBase();

protected:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="weapon")
	TObjectPtr<UStaticMeshComponent> WarriorWeapon;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="weapon")
	TObjectPtr<UBoxComponent>   WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetCurrentWeaponCollisionBox()const{return WeaponCollisionBox;}
};
