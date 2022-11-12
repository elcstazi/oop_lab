#include "Logger.h"

Logger::Logger(logLevel level, typesLogMethods method): level(level) {
	
	if (method == CONSOLE_LOG || method == CONSOLE_AND_FILE_LOG)
		addAppender(new LogToConsole);
	
	if (method == FILE_LOG || method == CONSOLE_AND_FILE_LOG)
		addAppender(new LogToFile);
}

Logger::~Logger() {
	for (auto cur : arrLogToSomewhere)
		delete cur;
}


//void Logger::Send(std::string message, std::string className, std::string strLevel) {
//	for (auto current : arrLogToSomewhere) {
//		current->write(message, className, strLevel);
//	}
//}


void Logger::Send(Message* message) {
	for (auto current : arrLogToSomewhere) {
		//current->write(message, className, strLevel);
		current->write(message);
	}
}


void Logger::Info(std::string message, std::string className) {
	//if (level == INFO || level == ALL) {
	//	Send(message, className, "INFO");
	//}
	Send(new IMessage(message, className));
}


void Logger::Trace(std::string message, std::string className) {
	//if (level == TRACE || level == ALL) {
	//	Send(message, className, "tRACE");
	//}
	Send(new TMessage(message, className));
}


void Logger::Warning(std::string message, std::string className) {
	//if (level == WARN || level == ALL) {
	//	Send(message, className, "WARN");
	//}
	Send(new WMessage(message, className));
}

void Logger::print(){
	for (auto current : arrLogToSomewhere) {
		if (dynamic_cast<LogToConsole*>(current))
			current->print();
	}
}

void Logger::Update(std::string message, std::string className, logLevel level){
	if ((this->level == INFO || this->level == ALL) && level == INFO)
		Info(message, className);
	if ((this->level == TRACE || this->level == ALL) && level == TRACE)
		Trace(message, className);
	if ((this->level == WARN || this->level == ALL) && level == WARN)
		Warning(message, className);
}

void Logger::Update(){
	print();
}

void Logger::addAppender(Appender* newLogTo) {
	arrLogToSomewhere.push_back(newLogTo);
}

