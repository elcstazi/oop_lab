#pragma once
#include <fstream>
#include <string>

class CommandsFile {
	
	const char* PATH = "commands.txt";
	std::ifstream file;
public: 

	CommandsFile();
	~CommandsFile();
	std::string read();
};