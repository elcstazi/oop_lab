#pragma once
#include "Types.h"
#include "Player.h"
#include "Cell.h"

class Cell;

class Event {
public:
	virtual void trigger(Player*, Cell*) = 0;
};

