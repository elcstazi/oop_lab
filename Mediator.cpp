#include "Mediator.h"

//Mediator::Mediator(Field* field) : commandReader(new Input(this)), controller(new Controller(this, field)) {}

//void Mediator::notify(Component* component, eDirection direction) {
//	if (component == commandReader && direction == UP) 
//}

void Mediator::notify(eDirection direction) {
	controller->start(direction);
}

//void Mediator::setSetup(Input* commandReader, Controller* controller) {
//	
//	this->commandReader = commandReader;
//	this->controller = controller;
//}

void Mediator::setSetup(Input* commandReader) {

	this->commandReader = commandReader;
	//this->controller = controller;
}