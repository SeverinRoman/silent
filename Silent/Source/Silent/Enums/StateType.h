#pragma once

#include "StateType.generated.h"

UENUM(BlueprintType)
enum class EStateType : uint8
{
	NONE = 0,

	IDLE = 1,
	MOVE = 2,
	CROUCH = 3,
	FALLING = 4,
	STANDBY = 5,
};