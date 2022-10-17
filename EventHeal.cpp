#include "EventHeal.h"

void EventHeal::trigger(Player* player, Cell* cell) {
	if (player->getHealth() != player->getPrimaryHealth()) {
		player->increaseHeath();
		cell->setType(SIMPLEPASSABLE);
	}
}