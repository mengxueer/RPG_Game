// xiaoyingtao


#include "Characters/WarriorCharacterBase.h"

#include "WarriorDebugHelp.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"


AWarriorCharacterBase::AWarriorCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled=false;

	 WarriorAbilitySystemComponent= CreateDefaultSubobject<UWarriorAbilitySystemComponent>("AbilitySystem");
	WarriorAttributeSet=CreateDefaultSubobject<UWarriorAttributeSet>("AttributeSet");
}

void AWarriorCharacterBase::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);
	if (WarriorAbilitySystemComponent) {
		Debug::print(TEXT("GAS初始化成功"));
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this,this);
	}
}

UAbilitySystemComponent* AWarriorCharacterBase::GetAbilitySystemComponent() const {
	return GetWarriorAbilitySystemComponent();
}



UWarriorAbilitySystemComponent* AWarriorCharacterBase::GetWarriorAbilitySystemComponent() const {
	return WarriorAbilitySystemComponent;
}

UWarriorAttributeSet* AWarriorCharacterBase::GetWarriorAttributeSet() const {
	return WarriorAttributeSet;
}




