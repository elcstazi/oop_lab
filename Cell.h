#pragma once
#include "Types.h"
#include "Event.h"
#include "Player.h"

class Event;

class Cell {
	kindOfCell type;
	Event* event;
public:
	Cell();
	Cell(kindOfCell);
	void setType(kindOfCell);
	kindOfCell getType();
	//void playerHere();
	void doEvent(Player*);
	void newEvent(Player*, Event*);
};
