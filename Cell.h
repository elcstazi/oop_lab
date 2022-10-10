#pragma once
#include "Types.h"
#include "Event.h"
#include "CellEvent.h"
#include "Player.h"

class Cell {

	kindOfCell Free;
	CellEvent* cellEvent;
	int type;
public:
	Cell();
	Cell(kindOfCell, int);
	void setTypeCell(kindOfCell);
	int getType();
	kindOfCell getFree();
};
