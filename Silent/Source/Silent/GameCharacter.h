#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"


class UGameInputComponent;


UCLASS()
class SILENT_API AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGameCharacter();

private:
	UPROPERTY()
	UGameInputComponent* GameInputComponent;

private:
	UFUNCTION()
	void Init();
	
private:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
