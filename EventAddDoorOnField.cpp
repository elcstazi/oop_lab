#include "EventAddDoorOnField.h"

void EventAddDoorOnField::trigger(Player* player, Cell* cell) {
	cell->setType(DOOR);
	player->getNumberKey() = 0;
	player->getNeedNumberKeys() = 0;

}