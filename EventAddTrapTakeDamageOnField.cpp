#include "EventAddTrapTakeDamageOnField.h"

void EventAddTrapTakeDamageOnField::trigger(Player* player, Cell* cell) {
	cell->setType(TRAPDAMAGE);
}