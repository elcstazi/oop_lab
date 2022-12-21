#pragma once
#include <conio.h>
#include "Types.h"
#include "Controller.h"
#include "CommandsMediator.h"



class Input : public Controller {
	eDirection dir;
	int gameover;

	CommandsMediator* mediator;

public:
	Input(Field*, Player*, std::vector<Observer*>&, CommandsMediator*);
	void userClicked();
	int getGameover();
};