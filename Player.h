#pragma once
#include "Types.h"

class Player {

	int type;
	int health, stength, coordinateX, coordinateY, numberKey;
	bool alive;
public:

	Player(int = 0);
	int& getX();
	int& getY();
	int gethealth();
	int getNumberKey();
	void increaseHeath();
	void decreaseHealth();
	void increaseKey();
	bool die();
};