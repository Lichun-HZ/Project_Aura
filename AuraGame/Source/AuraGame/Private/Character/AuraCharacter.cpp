// Copyright lichun


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	UCharacterMovementComponent* Movement = GetCharacterMovement();

	// 角色朝向跟随Movement的方向。
	Movement->bOrientRotationToMovement = true;
	Movement->RotationRate = FRotator(0, 400.0f, 0);
	Movement->bConstrainToPlane = true;
	Movement->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}
