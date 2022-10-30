#include "Door.h"
#include "Field.h"


void Door::trigger(Player* player, Field* field) {
	if (player->getNumberKey() == player->getNeedNumberKeys()) {
		field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
		field->getMargin()[player->getY()][player->getX()]->setEvent(0);
		player->setWin();
	}
}


//int Door::trigger(Player* player, Field* field) {
//	if (player->getNumberKey() == player->getNeedNumberKeys()) {
//		player->setWin();
//		return 1;
//	}
//	return 0;
//}