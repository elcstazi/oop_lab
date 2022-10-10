#pragma once
#include "Types.h"
//class Player {
//	char skin;
//	int health, coordinateX, coordinateY, step;
//	eDirection dir;
//public:
//	Player();
//	Player(char);
//	int getX();
//	int getY();
//	void setX(int);
//	void setY(int);
//	char getSkin();
//	//void setSkin(char);
//	int getHealth();
//	void getDamage();
//	void getElixir();
//	int getStep();
//	void setStep(int);
//	eDirection& getDir();
//};
class Player {
	
	int type;
	int health, coordinateX, coordinateY, numberKeys;
public:

	Player(int = 0);
	int& getNamberKeys();
	int& getX();
	int& getY();
	int getHealth();
};