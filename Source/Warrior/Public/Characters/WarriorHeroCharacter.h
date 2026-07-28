// xiaoyingtao

#pragma once

#include "CoreMinimal.h"
#include "WarriorCharacterBase.h"
#include "WarriorHeroCharacter.generated.h"

struct FInputActionValue;
class UInputDate;
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
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	TObjectPtr<UInputDate> InputDate;
private:
	UPROPERTY(BlueprintReadOnly,VisibleDefaultsOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<UCameraComponent> WarriorCamera;
	UPROPERTY(BlueprintReadOnly,VisibleDefaultsOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<USpringArmComponent> WarriorArm;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};


