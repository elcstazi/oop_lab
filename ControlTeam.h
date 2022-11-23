#pragma once
#include "CommandsMediator.h"


class ControlTeam {
	CommandsMediator* mediator;
public:
	ControlTeam(CommandsMediator*);
	int checkCorrectness();
	void handlCommands();
	void defaultCommands();
};