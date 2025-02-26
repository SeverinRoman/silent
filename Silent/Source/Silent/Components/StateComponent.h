#pragma once

#include "StateType.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateComponent.generated.h"


class UCharacterMovementComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChange, EStateType, StateType);


UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SILENT_API UStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStateComponent();

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	EStateType GetState() { return State; };

	UFUNCTION(BlueprintCallable)
	void SetState(EStateType NewState) { if (State == NewState) return; State = NewState; OnStateChange.Broadcast(NewState); };

public:
	UPROPERTY(BlueprintAssignable)
	FOnStateChange OnStateChange;

private:
	UPROPERTY(EditDefaultsOnly)
	bool IsDebug = false;

private:
	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;
	
private:
	UPROPERTY()
	AActor* Owner;
	
	UPROPERTY()
	EStateType State = EStateType::IDLE;

	UPROPERTY()
	FVector Velocity;

	UPROPERTY()
	float Direction;

	UPROPERTY()
	float Speed;

private:
	UFUNCTION()
	void Init();
	
	UFUNCTION()
	void Update();

	UFUNCTION()
	void UpdateData();
	
	UFUNCTION()
	void UpdateState();
	
	UFUNCTION()
	void Debug();

private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
