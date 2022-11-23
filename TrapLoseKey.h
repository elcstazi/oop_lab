#pragma once



#include "EventsOccurringProbability.h"

class TrapLoseKey : public EventsOccurringProbability {
public:
	std::string trigger(Player*, Field*);
};
