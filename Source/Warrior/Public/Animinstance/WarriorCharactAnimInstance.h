// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "Animinstance/WarriorAnimInstanceBase.h"
#include "WarriorCharactAnimInstance.generated.h"

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
	
};
