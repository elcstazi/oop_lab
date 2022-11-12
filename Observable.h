#pragma once
#include "Observer.h"
#include <vector>

class Observable {
protected:
	std::vector<Observer*> observers;
public:
	void Notify(std::string, std::string, logLevel);
	virtual void addObserver(Observer*) = 0;
};