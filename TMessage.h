#pragma once
#include "Message.h"

class TMessage : public Message {
public:
	TMessage(std::string, std::string);
	void castMessage(std::string, std::string);
};