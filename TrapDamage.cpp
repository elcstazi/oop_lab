#include "TrapDamage.h"
#include "Field.h"

std::string TrapDamage::trigger(Player* player, Field* field) {
	if (!(rand() % 2)) {
		player->decreaseHealth();
		field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
		field->getMargin()[player->getY()][player->getX()]->setEvent(0);
		return "TrapDamage";
	}
	return std::to_string(1);
}