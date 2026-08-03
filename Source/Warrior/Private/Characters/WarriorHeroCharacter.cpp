// xiaoyingtao


#include "Characters/WarriorHeroCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Component/Warriorinput/WarriorInputComponent.h"
#include "GameTags/WarriorTag.h"
#include "Camera/CameraComponent.h"
#include "Component/Combat/HeroCombatComponent.h"
#include "Components/CapsuleComponent.h"
#include "DateAsset/StartUpDate/DataAsset_StartUpDataBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AWarriorHeroCharacter::AWarriorHeroCharacter()
{
	//初始化相机和相机悬臂
	WarriorArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("WarriorArm"));
	WarriorArm->SetupAttachment(GetRootComponent());
	WarriorArm->bUsePawnControlRotation=true;

	bUseControllerRotationPitch=false;
	bUseControllerRotationRoll=false;
	bUseControllerRotationYaw=false;
	
	WarriorCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("WarriorCamera"));
	WarriorCamera->SetupAttachment(WarriorArm,USpringArmComponent::SocketName);
	WarriorCamera->bUsePawnControlRotation=false;

	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator (0,500.0f,0);
	GetCharacterMovement()->MaxWalkSpeed=400.0f;
	GetCapsuleComponent()->InitCapsuleSize(42.f,96.f);
	
	HeroCombat=CreateDefaultSubobject<UHeroCombatComponent>(TEXT("CombatComponent"));
}

void AWarriorHeroCharacter::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);
	// checkf(StartUpDataAsset,TEXT("启动数据为空!!!"))
	if (UDataAsset_StartUpDataBase* StartUpDataBase=  StartUpDataAsset.LoadSynchronous())
	{
		StartUpDataBase->GiveToAbilitiesSysComponent(Cast<UWarriorAbilitySystemComponent>(GetAbilitySystemComponent()));
	}
	
}


void AWarriorHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(InputDate)
	
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		
		if (ULocalPlayer* LP = PC->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
				LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				Subsystem->AddMappingContext(InputDate->InputMappingContext, 0);
			}
		}
	 }
	
	UWarriorInputComponent* WarriorInputComponent=Cast<UWarriorInputComponent>(PlayerInputComponent);
	 WarriorInputComponent->BindTagToAction(InputDate,warriorTag::Input_Move,ETriggerEvent::Triggered,this,&AWarriorHeroCharacter::Move);
	WarriorInputComponent->BindTagToAction(InputDate,warriorTag::Input_Look,ETriggerEvent::Triggered,this,&AWarriorHeroCharacter::Look);
}

void AWarriorHeroCharacter::Move(const FInputActionValue& Value) {
	const FVector2d InputAxis=Value.Get<FVector2d>();
	
	const FRotator ControlRot = GetControlRotation();
	const FRotator YawRot(0.f, ControlRot.Yaw, 0.f);

	const FVector Forward = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
	const FVector Right   = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);

	AddMovementInput(Forward, InputAxis.Y);
	AddMovementInput(Right,   InputAxis.X);
}

void AWarriorHeroCharacter::Look(const FInputActionValue& Value) {
	const FVector2d InputAxis=Value.Get<FVector2d>();
	
	AddControllerYawInput(InputAxis.X);
	AddControllerPitchInput(InputAxis.Y);
}
