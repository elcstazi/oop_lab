#include "LogToConsole.h" 



LogToConsole::LogToConsole(logLevel level): level(level) {}



void LogToConsole::addLog(Message* message) {
	this->message.push_back(message->getMessage());
}


void LogToConsole::print() {
	for (auto cur : message)
		std::cout << cur;
}

void LogToConsole::Update(std::string message, std::string className, logLevel level) {
	if ((this->level == INFO || this->level == ALL) && level == INFO)
		addLog(new IMessage(message, className));
	if ((this->level == TRACE || this->level == ALL) && level == TRACE)
		addLog(new TMessage(message, className));
	if ((this->level == WARN || this->level == ALL) && level == WARN)
		addLog(new WMessage(message, className));
}