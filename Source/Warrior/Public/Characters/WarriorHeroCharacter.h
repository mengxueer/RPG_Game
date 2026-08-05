// xiaoyingtao

#pragma once

#include "CoreMinimal.h"
#include "WarriorCharacterBase.h"
#include "WarriorHeroCharacter.generated.h"

struct FGameplayTag;
class UHeroCombatComponent;
class UInputDate;
struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorCharacterBase
{
	GENERATED_BODY()
public:
	AWarriorHeroCharacter();

	//接收控制时
	virtual void PossessedBy(AController* NewController) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(BlueprintReadOnly,VisibleDefaultsOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<UCameraComponent> WarriorCamera;
	UPROPERTY(BlueprintReadOnly,VisibleDefaultsOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<USpringArmComponent> WarriorArm;
	
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<UInputDate> InputDate;
	
	//战斗组件
	
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<UHeroCombatComponent> HeroCombat;
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void PushKeyToAbility(
	const FInputActionValue& Value,
	FGameplayTag Tag
);
	//void PullKeyToAbility(const FGameplayTag& Tag)const;
public:
	FORCEINLINE UHeroCombatComponent* GetCombatComponent()const
	{
		return HeroCombat;
	};
};


