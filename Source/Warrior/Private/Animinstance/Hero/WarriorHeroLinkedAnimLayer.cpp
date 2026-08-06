// xiaoxiao


#include "Animinstance/Hero/WarriorHeroLinkedAnimLayer.h"

#include "Animinstance/Hero/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetWarriorAnimInstanceBase()
{

	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());

}
