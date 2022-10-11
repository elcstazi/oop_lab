#pragma once
#include "Cell.h"
#include "Player.h"
#include <vector>
#include <ctime>
#include "FieldView.h"

class FieldView;

class Field{

	Player* player;
	std::vector<std::vector < Cell*>> margin;
	int height, width;
	FieldView* fieldView;

public:
	Field();
	Field(int, int);
	~Field();
	Field(const Field&);
	Field& operator=(const Field&);
	Field(Field&&);
	Field& operator=(Field&&);

	int getWidth();
	int getHeight();
	int getCurrentX();
	int getCurrentY();
	std::vector<std::vector < Cell*>> getMargin();
	void setCurrentY(int);
	void setCurrentX(int);
	void updatePlayer(Player*);


	void addFieldView(FieldView*);
	void notifyUpdate();
};