#pragma once


#include "Player.h"

class Field;

class Event {
public:
	virtual std::string trigger(Player*, Field*) = 0;
};
