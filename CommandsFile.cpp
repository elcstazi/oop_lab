#include "CommandsFile.h"


CommandsFile::CommandsFile(){
	file.open(PATH);
	if (!file.is_open())
		throw std::runtime_error("file open failture");
}

CommandsFile::~CommandsFile(){
	file.close();
}

std::string CommandsFile::read(){
	std::string str_comands;
	file >> str_comands;
	return str_comands;
}
