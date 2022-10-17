#pragma once
#include "Types.h"
#include <ctime>
#include <stdlib.h>

class Player {

	int type;
	int health, primaryHealth, stength, coordinateX, coordinateY, numberKey, needNumberKeys;
	bool alive;
public:

	Player(int = 0);
	int& getX();
	int& getY();
	int getHealth();
	int getPrimaryHealth();
	int& getNumberKey();
	int& getNeedNumberKeys();
	void increaseHeath();
	void decreaseHealth();
	void increaseKey();
	void decreaseKey();
	bool die();
};