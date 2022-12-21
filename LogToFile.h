#pragma once
#include "Observer.h"
#include <fstream>

class LogToFile: public Observer {
	std::ofstream file;
	const char* PATH = "Log.txt";
	std::string message;
	logLevel level;
public:
	LogToFile(logLevel);
	~LogToFile();
	friend std::ostream& operator<<(std::ostream&, const LogToFile&);
	void addLog(Message*);
	void print();
	void Update(std::string message, std::string className, logLevel level);
};