// xiaoyingtao

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "WarriorCharacterBase.generated.h"


class UWarriorAttributeSet;
class UWarriorAbilitySystemComponent;

UCLASS(Abstract)
class WARRIOR_API AWarriorCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AWarriorCharacterBase();
	//接收控制时
	virtual void PossessedBy(AController* NewController) override;

	//GAS获取接口
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	TObjectPtr<UInputDate> InputDate;
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AbilitySystem")
	TObjectPtr<UWarriorAbilitySystemComponent> WarriorAbilitySystemComponent;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AbilitySystem|Attribuetset")
	TObjectPtr<UWarriorAttributeSet> WarriorAttributeSet;

public:
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const;
	
	FORCEINLINE   UWarriorAttributeSet* GetWarriorAttributeSet() const;
};
