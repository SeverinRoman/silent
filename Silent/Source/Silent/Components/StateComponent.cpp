#include "StateComponent.h"

#include "KismetAnimationLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"


UStateComponent::UStateComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStateComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void UStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Update();
}

void UStateComponent::Init()
{
	Owner = GetOwner();
	if (!Owner) return;

	CharacterMovementComponent = Owner->GetComponentByClass<UCharacterMovementComponent>();
}

void UStateComponent::Update()
{
	if (!Owner) return;
	if (!CharacterMovementComponent) return;
	
	UpdateData();
	UpdateState();
	Debug();
}

void UStateComponent::UpdateData()
{
	Velocity = CharacterMovementComponent->Velocity;
	Speed = Velocity.Length();
	Direction = UKismetAnimationLibrary::CalculateDirection(Velocity, Owner->GetActorRotation());
}

void UStateComponent::UpdateState()
{
	if (CharacterMovementComponent->IsFalling())
	{
		State = EStateType::FALLING;
		return;
	}
	if (CharacterMovementComponent->IsCrouching())
	{
		State = EStateType::CROUCH;
		return;
	}

	if (State == EStateType::IDLE || State == EStateType::MOVE || State == EStateType::CROUCH || State == EStateType::FALLING)
	{
		if (Speed == 0.f)
		{
			State = EStateType::IDLE;
		}else
		{
			State = EStateType::MOVE;
		}
	}
}

void UStateComponent::Debug()
{
	if (!IsDebug) return;

	GEngine->AddOnScreenDebugMessage(-1, 0.001f, FColor::Green, FString::Printf(TEXT("Velocity is: %s"), *Velocity.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 0.001f, FColor::Green, FString::Printf(TEXT("Direction is: %f"), Direction));
	GEngine->AddOnScreenDebugMessage(-1, 0.001f, FColor::Green, FString::Printf(TEXT("Speed is:  %f"), Speed));
	GEngine->AddOnScreenDebugMessage(-1, 0.001f, FColor::Green, FString::Printf(TEXT("State is %s"), *UEnum::GetValueAsString(State)));
}

