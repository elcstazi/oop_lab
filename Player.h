#pragma once
#include "Observable.h"

class Player: public Observable {

	int health, primaryHealth, coordinateX, coordinateY, numberKey, needNumberKeys;
	bool dead, playerInDoor;
public:

	Player();
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
	bool& getPlayerInDoor();
};