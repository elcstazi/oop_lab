#pragma once
#include <string>
#include "Types.h"
class Observer {
public:
	virtual void Update(std::string, std::string, logLevel) = 0;
	virtual void Update() = 0;
};