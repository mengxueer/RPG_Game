// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "WarriorAttributeSet.generated.h"

	#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

//	ATTRIBUTE_ACCESSORS(UMyHealthSet, Health)

UCLASS()
class WARRIOR_API UWarriorAttributeSet : public UAttributeSet {
	GENERATED_BODY()
};
