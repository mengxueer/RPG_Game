// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DateAsset/InputDate.h"
#include "WarriorInputComponent.generated.h"



UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent {
	GENERATED_BODY()

public:
	UWarriorInputComponent();


	template <class UserClass, class UFuncType>
	void BindTagToAction(UInputDate* InputActionConfig,const FGameplayTag& InputTag, ETriggerEvent TriggerEvent,
	                     UserClass* Object, UFuncType FunctionName);
};

template <class UserClass, typename UFuncType>
void UWarriorInputComponent::BindTagToAction(UInputDate* InputActionConfig,const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, UFuncType
                                             FunctionName) {

	checkf(InputActionConfig,TEXT("在warriorinputcomponent组件下输入文件不存在配置文件"))
	if(UInputAction* InputAction =InputActionConfig->FindTagAction(InputTag)) {
		BindAction(InputAction,TriggerEvent,Object,FunctionName);
	}
}

