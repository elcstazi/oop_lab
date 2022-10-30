#include "TrapDamage.h"
#include "Field.h"

void TrapDamage::trigger(Player* player, Field* field) {
	if (!(rand() % 2)) {
		player->decreaseHealth();
		field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
		field->getMargin()[player->getY()][player->getX()]->setEvent(0);
	}
}


//int TrapDamage::trigger(Player* player, Field* field) {
//	if (!(rand() % 2)) {
//		player->decreaseHealth();
//		return 1;
//	}
//	return 0;
//}