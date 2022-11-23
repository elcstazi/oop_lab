#pragma once
#include <string>
#include <map>
#include "Types.h"


class ControlTeam;
class CommandsMediator {
	std::string str_commands;
	std::map<int, char> commands_map;
	ControlTeam* controlCommand;

public:
	void set_comands_handler(ControlTeam*);
	void set_comands(std::string);
	void handle_comands();
	std::map<int, char>& getMapCommand();
	std::string& getCommandStr();
	char getCommandUp();
	char getCommandLeft();
	char getCommandDown();
	char getCommandRight();
};