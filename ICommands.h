#pragma once
#include "CommandsMediator.h"

class ICommands {
public:
	virtual void read() = 0;
};