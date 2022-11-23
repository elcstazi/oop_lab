#include "Key.h"
#include "Field.h"

std::string Key::trigger(Player* player, Field* field) {
	player->increaseKey();
	field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
	field->getMargin()[player->getY()][player->getX()]->setEvent(0);
	return "Key";
}