#pragma once
//#include "Event.h"
#include "EventCellPlayer.h"

class EventPlayerInDoor : public EventCellPlayer {
public:
	void trigger(Player*, Cell*);
};