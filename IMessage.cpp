#include "IMessage.h"

IMessage::IMessage(std::string message, std::string className){
	castMessage(message, className);
}

void IMessage::castMessage(std::string message, std::string className){
	this->message = className + std::string("|") + std::string("INFO") + std::string("|") + message + std::string("\n");
}
