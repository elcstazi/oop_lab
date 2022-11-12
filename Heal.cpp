#include "Heal.h"
#include "Field.h"

void Heal::trigger(Player* player, Field* field) {
	if (player->getHealth() != player->getPrimaryHealth()) {
		player->increaseHeath();
		field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
		field->getMargin()[player->getY()][player->getX()]->setEvent(0);
		player->Notify("Event occurred, the player moved to a cell that increases health", "Heal", INFO);
	}
}


//int Heal::trigger(Player* player, Field* field) {
//	if (player->getHealth() != player->getPrimaryHealth()) { player->increaseHeath(); return 1; }
//	return 0;
//}