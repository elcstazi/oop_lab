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


//void Cell::playerHere() {
//	if (type == KEY) {
//		setType(SIMPLEPASSABLE);
//		delete event;
//		event = 0;
//	}
//}


void Cell::doEvent(Player* player){
	event->trigger(player, this);
}


void Cell::newEvent(Player* player, Event* newEvent) {
	event = newEvent;
	doEvent(player);
	delete event;
}
