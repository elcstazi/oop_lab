#pragma once
#include "Observer.h"
#include <vector>


class LogToConsole : public Observer {
	std::vector<std::string> message;
	logLevel level;
public:
	LogToConsole(logLevel);
	void addLog(Message*);
	void print();
	void Update(std::string, std::string, logLevel);
};