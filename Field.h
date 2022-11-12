#pragma once
#include "Cell.h"
#include "Player.h"
#include <vector>
#include "Key.h"
#include "Door.h"
#include "MapChange.h"
#include "TrapDamage.h"
#include "Heal.h"
#include "Observable.h"


class Field: public Observable {

	Player* player;
	std::vector<std::vector < Cell*>> margin;
	int height, width;
	
	
	std::string lessZeroHeight = "";
	std::string lessZeroWidth = "";

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
	void updatePlayer(Player*);
	void addCellWall(int);
	void addCellDoor();
	void addCellKey(int);
	void addCellHeal(int);
	void addCellTrapDamage(int);
	void addCellMapChange();


	using Observable::Notify;
	void Notify();
	void addObserver(Observer*);
};