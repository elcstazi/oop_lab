#pragma once



#include "EventsOccurringProbability.h"

class TrapLoseKey : public EventsOccurringProbability {
public:
	void trigger(Player*, Field*);
};

//#include "EventsOccurringProbability.h"
//
//class TrapLoseKey : public EventsOccurringProbability {
//public:
//	int trigger(Player*, Field*);
//};