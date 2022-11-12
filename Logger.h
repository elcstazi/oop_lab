#pragma once
#include "Types.h"
#include <vector>
#include "Appender.h"
#include "LogToConsole.h";
#include "LogToFile.h";
#include "IMessage.h";
#include "TMessage.h";
#include "WMessage.h";
#include "Observer.h"


class Logger: public Observer {
	std::vector<Appender*> arrLogToSomewhere;
	logLevel level;
public:
	void Update(std::string, std::string, logLevel);
	void Update();
	void addAppender(Appender*);
	Logger(logLevel, typesLogMethods);
	~Logger();
	//void Send(std::string, std::string, std::string);
	void Send(Message*);
	void Info(std::string, std::string);
	void Trace(std::string, std::string);
	void Warning(std::string, std::string);
	void print();
};
