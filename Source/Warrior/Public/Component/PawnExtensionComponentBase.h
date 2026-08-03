// xiaoxiao

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	template<class T>
	T*  GetOwnerPawn()const
	{
		//指定类型转换
		static_assert(TPointerIsConvertibleFromTo<T,APawn>::Value,TEXT("只能转换为指定的pawn类型"));
		return Cast<T>(GetOwner());
	}

	APawn* GetOwnerPawn() const
	{
		return GetOwnerPawn<APawn>();
	};
	template<class T>
	T* GetController()const
	{
		static_assert(TPointerIsConvertibleFromTo<T,APlayerController>::Value,TEXT("只能转换为指定的PlayerController类型"));
		return Cast<T>(GetOwnerPawn()->GetController());
	}
	
	APlayerController* GetController()const
	{
		return GetController<APlayerController>();
	}
};
