#pragma once
//#include "Event.h"
#include "EventCellPlayer.h"

class EventHeal : public EventCellPlayer {
public:
	void trigger(Player*, Cell*);
};