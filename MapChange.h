#pragma once
#include "EventsOccurringProbability.h"


class MapChange : public EventsOccurringProbability {
public:
	std::string trigger(Player*, Field*);
};