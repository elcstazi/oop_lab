#pragma once
#include "Observer.h"
#include <vector>
#include "Types.h"

class Observable {
protected:
	std::vector<Observer*> observers;
public:
	void Notify(std::string, std::string, logLevel);
	void addObserver(Observer*);
	void print();

};