#include "EventTrapTakeDamage.h"

void EventTrapTakeDamage::trigger(Player* player, Cell* cell) {
	player->decreaseHealth();
	cell->setType(SIMPLEPASSABLE);
}