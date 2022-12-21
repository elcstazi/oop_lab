#pragma once
#include "Message.h"

class IMessage : public Message {
public:
	IMessage(std::string, std::string);
	void castMessage(std::string, std::string);
};