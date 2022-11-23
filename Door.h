#pragma once
#include "EventsAlwaysHappening.h"


class Door : public EventsAlwaysHappening {
public:
	std::string trigger(Player*, Field*);
};
