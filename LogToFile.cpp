#include "LogToFile.h"

LogToFile::LogToFile() {
	file.open(PATH, std::fstream::app);
	if (!file.is_open())
		throw std::runtime_error("file open failture");

}

LogToFile::~LogToFile()
{
	file.close();
}


//void LogToFile::write(std::string message, std::string className, std::string strLevel) {
//	file << className << std::string("|") << strLevel << std::string("|") << message << std::string("\n");
//	//if (std::fputs((const char*)message, file) == EOF)
//	//	throw std::runtime_error("file write failure");
//
//}


std::ostream& operator<<(std::ostream& out, const LogToFile& logFile)
{
	out << logFile.message;
	return out;
}


void LogToFile::write(Message* message) {
	this->message = message->getMessage();
	file << this->message;
}

void LogToFile::print() {}
