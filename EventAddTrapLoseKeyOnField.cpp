#include "EventAddTrapLoseKeyOnField.h"

void EventAddTrapLoseKeyOnField::trigger(Player* player, Cell* cell) {
	cell->setType(TRAPLOSEKEY);
}