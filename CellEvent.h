#pragma once
#include "Event.h"
#include "Types.h"

class CellEvent : public Event {

public:
	void trigger() override;
};