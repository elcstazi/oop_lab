#pragma once
#include "Cell.h"
#include "Player.h"
#include <vector>
//#include <ctime>
#include "FieldView.h"

class FieldView;

class Field{

	Player* player;
	std::vector<std::vector < Cell*>> margin;
	int height, width, countKey, maxCountTrapLoseKey,currentCountTrapLoseKey, maxCountTrapDamage, currentCountTrapDamage;
	int maxCountHeal, currentCountHeal;
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
	std::vector<std::vector < Cell*>> getMargin();
	int getCurrentX();
	int getCurrentY();
	//void setCurrentY(int);
	//void setCurrentX(int);
	void updatePlayer(Player*);
	int& getKey();


	int getMaxCountTrapLoseKey();
	int& getCurrentCountTrapLoseKey();
	int getMaxCountTrapDamage();
	int& getCurrentCountTrapDamage();
	int getMaxCountHeal();
	int& getCurrentCountHeal();


	void addFieldView(FieldView*);
	void notifyUpdate();
};