#pragma once
#include <conio.h>
#include "Types.h"
#include "Controller.h"



class Input : public Controller {
	eDirection dir;
	int gameover;
public:
	Input(Field*, Player*);
	void userClicked();
	int getGameover();
};