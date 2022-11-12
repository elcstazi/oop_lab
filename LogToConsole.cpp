#include "LogToConsole.h" 

//void LogToConsole::write(std::string message, std::string className, std::string strLevel) {
//	this->message += className + std::string("|") + strLevel + std::string("|") + message + std::string("\n");
//	print();
//}


void LogToConsole::write(Message* message) {
	this->message += message->getMessage();
}


void LogToConsole::print() {
	std::cout << message;
}