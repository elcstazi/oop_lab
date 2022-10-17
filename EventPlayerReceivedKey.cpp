#include "EventPlayerReceivedKey.h"

void EventPlayerReceivedKey::trigger(Player* player, Cell* cell) {
	cell->setType(SIMPLEPASSABLE);
	player->increaseKey();
}