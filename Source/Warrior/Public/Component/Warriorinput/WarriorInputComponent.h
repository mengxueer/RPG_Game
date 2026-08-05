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


	template <class UserClass, typename UFuncType>
	void BindTagToAction(UInputDate* InputActionConfig,const FGameplayTag& InputTag, ETriggerEvent TriggerEvent,
	                     UserClass* Object, UFuncType FunctionName);
	template<class UserClass, typename UFuncType>
	void BindAbilityAction(UInputDate* InputActionConfig,UserClass* ObjectClass,UFuncType PushFunName,UFuncType PullFunName);
};

template <class UserClass, typename UFuncType>
void UWarriorInputComponent::BindTagToAction(UInputDate* InputActionConfig,const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, UFuncType
                                             FunctionName) {

	checkf(InputActionConfig,TEXT("在warriorinputcomponent组件下输入文件不存在配置文件"));
	if(UInputAction* InputAction =InputActionConfig->FindTagAction(InputTag)) {
		BindAction(InputAction,TriggerEvent,Object,FunctionName);
	}
}

template <class UserClass, typename UFuncType>
void UWarriorInputComponent::BindAbilityAction(UInputDate* InputActionConfig,
	UserClass* ObjectClass, UFuncType FunctionName,UFuncType PullFunName) {
	
	checkf(InputActionConfig,TEXT("在warriorinputcomponent组件下输入文件不存在配置文件"));
	for (const FInputTagToAction &AbilityAction : InputActionConfig->AbilityAction) {
		if (AbilityAction.IsValid()) {
			 BindAction(AbilityAction.InputAction,ETriggerEvent::Started,ObjectClass,FunctionName,AbilityAction.InputTag);
			 BindAction(AbilityAction.InputAction,ETriggerEvent::Completed,ObjectClass,PullFunName,AbilityAction.InputTag);
		}
	}
}

