#pragma once
#include <string>
#include "CommandsFile.h"
#include <map>
#include "Types.h"
#include <iostream>

class CommandsMediator {
	std::string str_commands;
	std::map<int, char> commands_map;
public:
	CommandsMediator(CommandsFile&);
	void setDefaultCommands();
	int checkCorrectness();
	void handlCommands();
	char getCommandUp();
	char getCommandLeft();
	char getCommandDown();
	char getCommandRight();
};