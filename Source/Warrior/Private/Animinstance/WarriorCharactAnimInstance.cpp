// xiaoxiao


#include "Animinstance/WarriorCharactAnimInstance.h"
#include "Characters/WarriorCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWarriorCharactAnimInstance::NativeInitializeAnimation() {
     OwningCharacter=Cast<AWarriorCharacterBase>(TryGetPawnOwner());
     if (OwningCharacter)
     {
          OwningMovementComponent=OwningCharacter->GetCharacterMovement();
     }
   
}

void UWarriorCharactAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds) {
     if (OwningCharacter&&OwningMovementComponent)
     {
         GroundSpeed= OwningCharacter->GetVelocity().Size2D();
     	bIsMoving= GroundSpeed>1.f;//OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
     }
}
