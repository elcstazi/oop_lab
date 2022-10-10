#pragma once
#include "Mediator.h"

class Component {
protected:
	Mediator* mediator;
public:
	Component(Mediator*);
};