// xiaoxiao


#include "Animinstance/Hero/WarriorHeroAnimInstance.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OWnWarriorCharacterRef=Cast<AWarriorHeroCharacter>(OwningCharacter);
	}
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bIsMoving)
	{
		IdleToTime=0;
		bShouldEnterRelaxState=false;
	}
	else
	{
		IdleToTime+=DeltaSeconds;
		bShouldEnterRelaxState=(EnterRelaxTime>=IdleToTime);
	}
}
