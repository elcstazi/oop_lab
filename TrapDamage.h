#pragma once


#include "EventsOccurringProbability.h"

class TrapDamage : public EventsOccurringProbability {
public:
	void trigger(Player*, Field*);
};

//#include "EventsOccurringProbability.h"
//
//class TrapDamage : public EventsOccurringProbability {
//public:
//	int trigger(Player*, Field*);
//};