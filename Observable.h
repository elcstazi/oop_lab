#pragma once
#include "Observer.h"

class Observable {
	Observer* observer;
public:
	void addObserver(Observer*);
	void notifyUpdate();

};