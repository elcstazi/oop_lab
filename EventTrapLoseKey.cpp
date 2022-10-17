#include "EventTrapLoseKey.h"

void EventTrapLoseKey::trigger(Player* player, Cell* cell) {
	if (player->getNumberKey()) {
		player->decreaseKey();
		cell->setType(SIMPLEPASSABLE);
	}
}