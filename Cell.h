#pragma once
#include "Types.h"
#include "Event.h"
#include "CellEvent.h"
#include "Player.h"

class Cell {
	kindOfCell free;
	int type;
public:
	Cell();
	Cell(kindOfCell, int);
	int getType();
	kindOfCell getFree();
};
