#pragma once
#include "EventCellField.h"
//#include "Event.h"

class EventAddTrapTakeDamageOnField : public EventCellField {
public:
	void trigger(Player*, Cell*);
};