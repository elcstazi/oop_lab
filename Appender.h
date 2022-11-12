#pragma once
#include <string>
#include <iostream>
#include "Message.h"

class Appender {
public:
	//virtual void write(std::string, std::string, std::string) = 0;
	virtual void write(Message*) = 0;
	virtual void print() = 0;
};