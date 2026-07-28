// xiaoxiao

#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputDate.generated.h"
class UInputMappingContext;
class UInputAction;

USTRUCT(BlueprintType)
struct FInputTagToAction {
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FGameplayTag InputTag;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UInputAction> InputAction;
};
/**
 * 
 */
UCLASS(BlueprintType)
class WARRIOR_API UInputDate :public UDataAsset
{

	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> InputMappingContext;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TArray<FInputTagToAction> InputTagToAction;


	 UInputAction* FindTagAction(const FGameplayTag &InputTag)const;
};
