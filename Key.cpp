#include "Key.h"
#include "Field.h"

void Key::trigger(Player* player, Field* field) {
	player->increaseKey();
	field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
	field->getMargin()[player->getY()][player->getX()]->setEvent(0);
}


//int Key::trigger(Player* player, Field* field) {
//	player->increaseKey();
//	return 1;
//}