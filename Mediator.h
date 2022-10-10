#pragma once
#include "Input.h"
#include "Controller.h"
#include "Component.h"

class Mediator {
	Input* commandReader;
	Controller* controller;
public:
	//Mediator(Field*);
	

	//void notify(Component*, eDirection);
	//void setSetup(Input*, Controller*);
	void notify(eDirection);
	void setSetup(Input*);
};