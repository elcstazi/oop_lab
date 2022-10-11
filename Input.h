#pragma once
#include <conio.h>
#include "Types.h"
#include "Field.h"
#include "Controller.h"

class Input : public Controller{
	eDirection dir;
	int gameover;
public:
	Input(Field*);
	void userClicked();
};