#pragma once
#include "Appender.h"
#include <fstream>

class LogToFile: public Appender {
	std::ofstream file;
	const char* PATH = "Log.txt";
	std::string message;
public:
	LogToFile();
	~LogToFile();
	friend std::ostream& operator<<(std::ostream&, const LogToFile&);
	//void write(std::string, std::string, std::string);
	void write(Message*);
	void print();
};