#include "CellView.h"

void CellView::draw(kindOfCell type) {

	switch (type) {
	case IMPASSABLE:
		std::cout << '#';
		break;
	case KEY:
		std::cout << '!';
		break;
	case DOOR:
		std::cout << '*';
		break;
	//case TRAPLOSEKEY:
	//	std::cout << '1';
	//	break;
	//case TRAPDAMAGE:
	//	std::cout << '?';
	//	break;
	//case HEAL:
	//	std::cout << '2';
	//	break;
	default:
		std::cout << ' ';
	}
}