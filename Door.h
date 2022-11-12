#pragma once
#include "EventsAlwaysHappening.h"


class Door : public EventsAlwaysHappening {
public:
	void trigger(Player*, Field*);
};

//class Door : public EventsAlwaysHappening {
//public:
//	int trigger(Player*, Field*);
//};