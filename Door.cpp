#include "Door.h"
#include "Field.h"


std::string Door::trigger(Player* player, Field* field) {
	if (player->getNumberKey() == player->getNeedNumberKeys()) {
		field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
		field->getMargin()[player->getY()][player->getX()]->setEvent(0);
		player->getPlayerInDoor() = true;
		return "Door";
	}
	return std::to_string(1);
}
