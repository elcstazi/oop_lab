#include "MapChange.h"
#include "Field.h"


std::string MapChange::trigger(Player* player, Field* field) {
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
		return "MapChange";
	}
	return std::to_string(1);
}