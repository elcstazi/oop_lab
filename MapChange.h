#pragma once
#include "EventsOccurringProbability.h"

//class MapChange : public EventsOccurringProbability {
//public:
//	int trigger(Player*, Field*);
//};

class MapChange : public EventsOccurringProbability {
public:
	void trigger(Player*, Field*);
};