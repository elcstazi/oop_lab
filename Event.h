#pragma once
#include "Types.h"
#include "Player.h"

class Event {
public:
	virtual void trigger() = 0;
	virtual void use() = 0;
};

