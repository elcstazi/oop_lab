#pragma once
//#include "Event.h"
#include "EventCellPlayer.h"

class Cell;

class EventPlayerReceivedKey : public EventCellPlayer {
public:
	void trigger(Player*, Cell*);
};