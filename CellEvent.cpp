#include "CellEvent.h"

void CellEvent::trigger(kindOfCell& Free, int& typeCell, Player* player) {
	
	if (Free == IMPASSABLE) return;

	if (typeCell == 1) player->getNamberKeys()++;
	if (typeCell != 0) typeCell = 4;
}
