#include "Door.h"
#include "Field.h"


void Door::trigger(Player* player, Field* field) {
	if (player->getNumberKey() == player->getNeedNumberKeys()) {
		field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
		field->getMargin()[player->getY()][player->getX()]->setEvent(0);
		player->getPlayerInDoor() = true;
		player->Notify("The event occurred, the player walked through the door", "Door", INFO);
	}
}


//int Door::trigger(Player* player, Field* field) {
//	if (player->getNumberKey() == player->getNeedNumberKeys()) {
//		player->setWin();
//		return 1;
//	}
//	return 0;
//}