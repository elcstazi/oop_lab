#pragma once
#include "EventsAlwaysHappening.h"


class Key : public EventsAlwaysHappening {
public:
	void trigger(Player*, Field*);
};


//class Key : public EventsAlwaysHappening {
//public:
//	int trigger(Player*, Field*);
//};