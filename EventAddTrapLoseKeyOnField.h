#pragma once
#include "EventCellField.h"
//#include "Event.h"

class EventAddTrapLoseKeyOnField : public EventCellField {
public:
	void trigger(Player*, Cell*);
};