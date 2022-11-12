#include "TrapLoseKey.h"


void TrapLoseKey::trigger(Player* player, Field* field) {
	if (!(rand() % 2)) {
		player->decreaseKey();

	}
}


//int TrapLoseKey::trigger(Player* player, Field* field) {
//	if (!(rand() % 2)) {
//		player->decreaseKey();
//		return 1;
//	}
//	return 0;
//}