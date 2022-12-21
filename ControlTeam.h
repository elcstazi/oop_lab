#pragma once
#include "CommandsMediator.h"


class ControlTeam {
	CommandsMediator* mediator;
public:
	ControlTeam(CommandsMediator*);
	int checkCorrectness();
	std::map<char, int> handlCommands();
	std::string defaultCommands();
};