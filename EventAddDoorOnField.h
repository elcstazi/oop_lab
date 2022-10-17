#pragma once
#include "EventCellField.h"
//#include "Event.h"

//class EventAddDoorOnField : public Event {
class EventAddDoorOnField : public EventCellField {
public:
	void trigger(Player*, Cell*);
};