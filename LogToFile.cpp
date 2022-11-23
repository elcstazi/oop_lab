#include "LogToFile.h"

LogToFile::LogToFile(logLevel level): level(level) {
	file.open(PATH, std::fstream::app);
	if (!file.is_open())
		throw std::runtime_error("file open failture");

}

LogToFile::~LogToFile()
{
	file.close();
}



std::ostream& operator<<(std::ostream& out, const LogToFile& logFile)
{
	out << logFile.message;
	return out;
}


void LogToFile::addLog(Message* message) {
	this->message = message->getMessage();
	file << this->message;
}

void LogToFile::print(){}


void LogToFile::Update(std::string message, std::string className, logLevel level) {
	if ((this->level == INFO || this->level == ALL) && level == INFO)
		addLog(new IMessage(message, className));
	if ((this->level == TRACE || this->level == ALL) && level == TRACE)
		addLog(new TMessage(message, className));
	if ((this->level == WARN || this->level == ALL) && level == WARN)
		addLog(new WMessage(message, className));
}