#pragma once
#include "Cell.h"
#include "Player.h"
#include <vector>
#include <ctime>
#include "FieldView.h"
#include "Observable.h"

class Field: public Observable {

	Player* player;
	std::vector<std::vector < Cell*>> margin;
	int height, width;
	Observer* fieldView;

public:
	Field();
	Field(int, int);
	~Field();

	int getWidth();
	int getHeight();
	int getCurrentX();
	int getCurrentY();
	std::vector<std::vector < Cell*>> getMargin();
	void setCurrentY(int);
	void setCurrentX(int);
};