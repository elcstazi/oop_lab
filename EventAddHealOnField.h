#pragma once
#include "EventCellField.h"
//#include "Event.h"

class EventAddHealOnField : public EventCellField {
public:
	void trigger(Player*, Cell*);
};