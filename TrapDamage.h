#pragma once


#include "EventsOccurringProbability.h"

class TrapDamage : public EventsOccurringProbability {
public:
	std::string trigger(Player*, Field*);
};