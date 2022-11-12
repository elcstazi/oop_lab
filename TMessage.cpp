#include "TMessage.h"

TMessage::TMessage(std::string message, std::string className){
	castMessage(message, className);
}

void TMessage::castMessage(std::string message, std::string className){
	this->message = className + std::string("|") + std::string("TRACE") + std::string("|") + message + std::string("\n");
}
