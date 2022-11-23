#include "Cell.h"


Cell::Cell() : type(SIMPLEPASSABLE), event(0) {}
Cell::Cell(kindOfCell type) {
	this->type = type;
	event = 0;
}


void Cell::setType(kindOfCell type) {
	this->type = type;
}


kindOfCell Cell::getType() {

	return type;
}


void Cell::setEvent(Event* newEvent) {
	event = newEvent;
}


Event* Cell::getEvent() {
	return event;
}