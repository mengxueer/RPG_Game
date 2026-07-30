// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "Animinstance/WarriorAnimInstanceBase.h"
#include "WarriorCharactAnimInstance.generated.h"

class AWarriorCharacterBase;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorCharactAnimInstance : public UWarriorAnimInstanceBase
{
	GENERATED_BODY()
public:
     virtual void NativeInitializeAnimation()override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds)override;
protected:
	UPROPERTY()
	TObjectPtr<AWarriorCharacterBase> OwningCharacter;
	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> OwningMovementComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float GroundSpeed;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsMoving;
	
};
