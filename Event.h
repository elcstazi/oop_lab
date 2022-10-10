#pragma once
#include "Types.h"
#include "Player.h"

class Event {
public:
	virtual void trigger(kindOfCell&, int&, Player*) = 0;
};

