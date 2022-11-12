#pragma once
#include "EventsAlwaysHappening.h"



class Heal : public EventsAlwaysHappening {
public:
	void trigger(Player*, Field*);
};

//class Heal : public EventsAlwaysHappening {
//public:
//	int trigger(Player*, Field*);
//};