#pragma once
//#include "Event.h"
#include "EventCellPlayer.h"

class EventTrapTakeDamage : public EventCellPlayer {
public:
	void trigger(Player*, Cell*);
};