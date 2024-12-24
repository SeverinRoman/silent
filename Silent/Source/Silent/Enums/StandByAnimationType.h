#pragma once

#include "StandByAnimationType.generated.h"

UENUM(BlueprintType)
enum class EStandByAnimationType : uint8
{
	NONE = 0,

	STANDBY_0 = 1,
	STANDBY_1 = 2,
	STANDBY_2 = 3,
	STANDBY_3 = 4,
	STANDBY_4 = 5,
	STANDBY_5 = 6,

	STANDBY_CROUCH_0 = 10,
	STANDBY_CROUCH_1 = 11,
	STANDBY_CROUCH_2 = 12,
	STANDBY_CROUCH_3 = 13,
	STANDBY_CROUCH_4 = 14,
};