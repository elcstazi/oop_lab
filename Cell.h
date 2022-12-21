#pragma once
#include "Types.h"

class Event;


class Cell {
	kindOfCell type;
	Event* event;
public:
	Cell();
	Cell(kindOfCell);
	void setType(kindOfCell);
	kindOfCell getType();

	void setEvent(Event*);
	Event* getEvent();
};