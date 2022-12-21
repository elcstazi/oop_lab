#pragma once
#include <fstream>
#include "ICommands.h"

class InputFile: public ICommands{
	const char* PATH = "commands.txt";
	std::ifstream file;
	CommandsMediator* mediator;
public: 
	InputFile(CommandsMediator*);
	~InputFile();
	void read();
};