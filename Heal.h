#pragma once
#include "EventsAlwaysHappening.h"



class Heal : public EventsAlwaysHappening {
public:
	std::string trigger(Player*, Field*);
};