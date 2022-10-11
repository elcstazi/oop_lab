#pragma once
#include "Types.h"
#include "Event.h"
#include "CellEvent.h"
#include "Player.h"

class Cell {
	kindOfCell free;
	int type;
	Event* event;
public:
	Cell();
	Cell(kindOfCell, int);
	int getType();
	void setType(int);
	kindOfCell getFree();
	void playerHere();
};
