#pragma once
#include <string>
#include <map>
#include "Types.h"


class ControlTeam;
class CommandsMediator {
	std::string str_commands;
	std::map<char,int> commands_map;
	ControlTeam* controlCommand;

public:
	void set_comands_handler(ControlTeam*);
	void set_comands(std::string);
	void handle_comands();
	std::map<char, int>& getMapCommand();
	std::string& getCommandStr();
	eDirection getCurrentCommand(char);
};