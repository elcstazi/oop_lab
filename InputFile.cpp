#include "InputFile.h"

InputFile::InputFile(CommandsMediator* mediator): mediator(mediator) {
	file.open(PATH);
	if (!file.is_open())
		throw std::runtime_error("file open failture");
}

InputFile::~InputFile(){
	file.close();
}

void InputFile::read(){
	std::string str_comands;
	file >> str_comands;
	mediator->set_comands(str_comands);
}
