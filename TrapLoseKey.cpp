#include "TrapLoseKey.h"


std::string TrapLoseKey::trigger(Player* player, Field* field) {
	if (!(rand() % 2)) {
		player->decreaseKey();
		return "TrapLoseKey";
	}
	return std::to_string(1);
}
