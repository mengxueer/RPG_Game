// xiaoyingtao

#pragma once

#include "CoreMinimal.h"
#include "WarriorCharacterBase.h"
#include "WarriorHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorCharacterBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	
};


