// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "Animinstance/WarriorCharactAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"
#include "WarriorHeroAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public UWarriorCharactAnimInstance {
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation()override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds)override;
protected:
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="Anim|Refrences")
	TObjectPtr<AWarriorHeroCharacter> OWnWarriorCharacterRef; 
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="Anim|Data")//空闲状态
	bool bShouldEnterRelaxState	;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Anim|Data")
	//空闲时间
	float EnterRelaxTime = 5.0f	;
	//空闲经过时间
	float IdleToTime;
};
