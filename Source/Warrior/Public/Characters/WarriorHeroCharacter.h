// xiaoyingtao

#pragma once

#include "CoreMinimal.h"
#include "WarriorCharacterBase.h"
#include "WarriorHeroCharacter.generated.h"

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

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};


