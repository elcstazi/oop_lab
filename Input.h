#pragma once
#include <conio.h>
#include "Types.h"
#include "Field.h"
#include "Component.h"

class Input  : public Component {
	eDirection dir;
	int gameover;
public:
	Input();
	void userClicked();
	//Input(Mediator*);
	int getGameover();
	
};