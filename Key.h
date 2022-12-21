#pragma once
#include "EventsAlwaysHappening.h"


class Key : public EventsAlwaysHappening {
public:
	std::string trigger(Player*, Field*);
};