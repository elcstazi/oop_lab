#pragma once
#include "Cell.h"
#include "Player.h"
#include "Cell.h"
#include <vector>
#include <ctime>
//----------------------------------------------------------
#include "FieldView.h"

class Field {
	
	Player* player;
	std::vector<std::vector < Cell*>> margin;
	int height, width;
	int key, elixir, numberKey;
	int numberDoor = 0;
	//-------------------------------------------------------------------------
	FieldView* consoleView;

public:
	Field();
	Field(int, int);
	Field(const Field&);
	Field& operator=(const Field&); 
	Field(Field&&);
	Field& operator=(Field&&);
	~Field();
	//-----------------------------
	void notifyUpdate();
	void addFieldView(FieldView*);
	//-----------------------------
	void updatePlayer(Player*);
	int getWidth();
	int getHeight();
	int getCurrentX();
	int getCurrentY();
	std::vector<std::vector < Cell*>> getMargin();
	void setCurrentY(int);
	void setCurrentX(int);
	void addKey();
	int getPlayerNumberkeys();
	void setPlayerNumberKeys();
	int getplayerHealth();
	void addDoor();
	int getNumberKeys();
	int& getNumberDoor();
	

};