#pragma once
#include "Cell.h"
#include "Player.h"
#include <vector>
#include "Key.h"
#include "Door.h"
#include "MapChange.h"
#include "TrapDamage.h"
#include "Heal.h"
#include <utility>



class Field {

	Player* player;
	std::vector<std::vector < Cell*>> margin;
	int height, width;

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
	int& getCurrentX();
	int& getCurrentY();
	void updatePlayer(Player*);
	//void addCellWall(int);
	//void addCellDoor();
	//void addCellKey(int);
	//void addCellHeal(int);
	//void addCellTrapDamage(int);
	//void addCellMapChange();
	void Card_initialization();
	std::pair <int, int> find_empty_cell();


};