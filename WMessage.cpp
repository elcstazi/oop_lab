#include "WMessage.h"

WMessage::WMessage(std::string message, std::string className){
	castMessage(message, className);
}

void WMessage::castMessage(std::string message, std::string className){
	this->message = className + std::string("|") + std::string("WARN") + std::string("|") + message + std::string("\n");
}
