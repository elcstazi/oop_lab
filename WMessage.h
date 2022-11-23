#pragma once
#include "Message.h"

class WMessage : public Message {
public:
	WMessage(std::string, std::string);
	void castMessage(std::string, std::string);
};