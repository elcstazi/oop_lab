#pragma once
#include "Types.h"

class Player {

	int type;
	int health, coordinateX, coordinateY;
public:

	Player(int = 0);
	int& getX();
	int& getY();
};