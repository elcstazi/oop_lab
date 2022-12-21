#include "Heal.h"
#include "Field.h"

std::string Heal::trigger(Player* player, Field* field) {
	if (player->getHealth() != player->getPrimaryHealth()) {
		player->increaseHeath();
		field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
		field->getMargin()[player->getY()][player->getX()]->setEvent(0);
		return "Heal";
	}
	return std::to_string(1);
}