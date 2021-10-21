#pragma once
#include "bx/timer.h"

class Time {
public:
	static int64_t offset;
	static float getTime() { return (float)((bx::getHPCounter() - offset) / double(bx::getHPFrequency())); }
};