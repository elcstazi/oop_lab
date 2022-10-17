#include "EventAddKeyOnField.h"

void EventAddKeyOnField::trigger(Player* player, Cell* cell){
	cell->setType(KEY);
}