#pragma once
#include "EventCellField.h"
//#include "Event.h"

class EventAddKeyOnField: public EventCellField {
public:
	void trigger(Player*, Cell*);
};