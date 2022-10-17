#pragma once
//#include "Event.h"
#include "EventCellPlayer.h"

class Cell;

class EventTrapLoseKey: public EventCellPlayer {
public:
	void trigger(Player*, Cell*);
};