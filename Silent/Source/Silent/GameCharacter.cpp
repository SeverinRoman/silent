#include "GameCharacter.h"

#include "GameInputComponent.h"


AGameCharacter::AGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGameCharacter::Init()
{
	GameInputComponent = FindComponentByClass<UGameInputComponent>();

	if (GameInputComponent)
	{
		GameInputComponent->SetupPlayerInputComponent(InputComponent);
	}
}

