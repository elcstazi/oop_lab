#pragma once
#include <string>

class Message {
protected:
	std::string message;
public:
	virtual void castMessage(std::string, std::string) = 0;
	std::string getMessage();

};
