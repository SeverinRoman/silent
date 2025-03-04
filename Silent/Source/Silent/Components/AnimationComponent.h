#pragma once

// #include "StandByAnimationType.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.generated.h"


class USkeletalMeshComponent;

enum class EStandByAnimationType: uint8;
enum class EAnimationType: uint8;


UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SILENT_API UAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAnimationComponent();

public:
	UFUNCTION(BlueprintCallable)
	void Play(UAnimMontage* AnimMontage);
	
	UFUNCTION(BlueprintCallable)
	void Stop(float Blend = 0.1f);

public:
	UFUNCTION()
	void PlayStandBy(EStandByAnimationType StandByAnimation);

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<EAnimationType, UAnimMontage*> Animations;
	
	UPROPERTY(EditDefaultsOnly)
	TMap<EStandByAnimationType, UAnimMontage*> StandByAnimations;
	
private:
	UPROPERTY()
	AActor* Owner;
	
	UPROPERTY()
	UAnimInstance* AnimInstance;

private:
	UPROPERTY()
	USkeletalMeshComponent* SkeletalMeshComponent;
	
private:
	UFUNCTION()
	void Init();
	
private:
	virtual void BeginPlay() override;
	
};
