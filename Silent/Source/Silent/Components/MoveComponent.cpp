#include "MoveComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

#include "StateComponent.h"
#include "AnimationComponent.h"


UMoveComponent::UMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMoveComponent::Init()
{
	Owner = GetOwner();
	if (!Owner) return;

	Character = Cast<ACharacter>(Owner);
	
	CharacterMovementComponent = Owner->GetComponentByClass<UCharacterMovementComponent>();
	StateComponent = Owner->GetComponentByClass<UStateComponent>();
	AnimationComponent = Owner->GetComponentByClass<UAnimationComponent>();
	
}

void UMoveComponent::Crouch()
{
	if(CharacterMovementComponent)
	{
		CharacterMovementComponent->Crouch();
	}
}

void UMoveComponent::UnCrouch()
{
	if(CharacterMovementComponent)
	{
		CharacterMovementComponent->UnCrouch();
	}
}

void UMoveComponent::Jump()
{
	if(CharacterMovementComponent)
	{
		Character->Jump();
	}
}

void UMoveComponent::UnJump()
{
	if(CharacterMovementComponent)
	{
		Character->StopJumping();
	}
}
