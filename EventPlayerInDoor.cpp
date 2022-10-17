#include "EventPlayerInDoor.h"

void EventPlayerInDoor::trigger(Player* player, Cell* cell) {
	cell->setType(SIMPLEPASSABLE);
}