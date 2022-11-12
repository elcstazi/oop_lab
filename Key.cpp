#include "Key.h"
#include "Field.h"

void Key::trigger(Player* player, Field* field) {
	player->increaseKey();
	field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
	field->getMargin()[player->getY()][player->getX()]->setEvent(0);
	player->Notify("The event occurred, the player moved to the cell where the key is", "Key", INFO);
}


//int Key::trigger(Player* player, Field* field) {
//	player->increaseKey();
//	return 1;
//}