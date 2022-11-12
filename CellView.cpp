#include "CellView.h"

void CellView::draw(kindOfCell type) {

	switch (type) {
	case IMPASSABLE:
		std::cout << '#';
		break;
	case CELL_KEY:
		std::cout << '!';
		break;
	case CELL_DOOR:
		std::cout << '*';
		break;
	//case TRAPDAMAGE:
	//	std::cout << '?';
	//	break;
	//case HEAL:
	//	std::cout << '2';
	//	break;
	//case MAPCHANGE:
	//	std::cout << '3';
	//	break;
	default:
		std::cout << ' ';
	}
}