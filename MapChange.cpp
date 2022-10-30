#include "MapChange.h"
#include "Field.h"

//int MapChange::trigger(Player* player, Field* field) {
//	if (!(rand() % 3)) {
//		int y, x, height = field->getHeight(), width = field->getWidth();
//		kindOfCell type;
//		do {
//			y = (height + (rand() - rand()) % height) % height;
//			x = (width + (rand() - rand()) % width) % width;
//			type = field->getMargin()[y][x]->getType();
//		} while (type == CELL_KEY || type == CELL_DOOR);
//		
//		field->getMargin()[y][x]->setType(IMPASSABLE);
//		field->getMargin()[y][x]->setEvent(0);
//		//int random = rand() % 4;
//		//if (random == 0) {
//		//	field->getMargin()[y][x]->setEvent(new Heal());
//		//	field->getMargin()[y][x]->setType(HEAL);
//		//}
//		//else if (random == 1) {
//		//	field->getMargin()[y][x]->setType(IMPASSABLE);
//		//	field->getMargin()[y][x]->setEvent(0);
//		//}
//		//else if (random == 2) {
//		//	field->getMargin()[y][x]->setType(TRAPDAMAGE);
//		//	field->getMargin()[y][x]->setEvent(new TrapDamage());
//		//}
//		//else if (random == 3) {
//		//	field->getMargin()[y][x]->setType(SIMPLEPASSABLE);
//		//	field->getMargin()[y][x]->setEvent(0);
//		//}
//		return 1;
//	}
//	return 0;
//}


void MapChange::trigger(Player* player, Field* field) {
	if (!(rand() % 3)) {
		int y, x, height = field->getHeight(), width = field->getWidth();
		kindOfCell type;
		do {
			y = (height + (rand() - rand()) % height) % height;
			x = (width + (rand() - rand()) % width) % width;
			type = field->getMargin()[y][x]->getType();
		} while (type == CELL_KEY || type == CELL_DOOR);

		field->getMargin()[y][x]->setType(IMPASSABLE);
		field->getMargin()[y][x]->setEvent(0);
	}
}