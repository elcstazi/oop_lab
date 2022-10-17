#include "EventAddHealOnField.h"

void EventAddHealOnField::trigger(Player* player, Cell* cell) {
	cell->setType(HEAL);
}