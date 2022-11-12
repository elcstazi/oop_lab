#pragma once
#include "Appender.h"

class LogToConsole : public Appender {
	std::string message;
public:
	//void write(std::string, std::string, std::string);
	void write(Message*);
	void print();
};