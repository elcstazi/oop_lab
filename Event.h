#pragma once


#include "Player.h"

class Field;

class Event {
public:
	virtual void trigger(Player*, Field*) = 0;
};

//#include "Player.h"
//
//class Field;
//
//class Event {
//public:
//	virtual int trigger(Player*, Field*) = 0;
//};