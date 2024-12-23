#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveComponent.generated.h"


class UCharacterMovementComponent;
class UAnimationComponent;
class UStateComponent;


UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SILENT_API UMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMoveComponent();

public:
	UFUNCTION(BlueprintCallable)
	void Crouch();
	
	UFUNCTION(BlueprintCallable)
	void UnCrouch();
	
	UFUNCTION(BlueprintCallable)
	void Jump();
	
	UFUNCTION(BlueprintCallable)
	void UnJump();

private:
	UFUNCTION()
	void Init();

private:
	UPROPERTY()
	AActor* Owner;
	
	UPROPERTY()
	ACharacter* Character;

private:
	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;
	
	UPROPERTY()
	UStateComponent* StateComponent;

	UPROPERTY()
	UAnimationComponent* AnimationComponent;

private:	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
