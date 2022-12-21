#pragma once
#include <iostream>
#include <string>
#include "Types.h"
#include "IMessage.h"
#include "TMessage.h"
#include "WMessage.h"
class Observer {
public:
	virtual void Update(std::string, std::string, logLevel) = 0;
	virtual void print() {};
};