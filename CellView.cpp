#include "CellView.h"

void CellView::draw(kindOfCell free,int type) {
	
	switch (free) {
	case SIMPLEPASSABLE:
		switch (type) {
		case 0:
			std::cout << '*';
			break;
		case 1:
			std::cout << '!';
			break;
		case 2:
			std::cout << '?';
			break;
		case 3:
			std::cout << '?';
			break;
		case 4:
			std::cout << ' ';
			break;
		}
		break;
	case IMPASSABLE:
		std::cout << '#';
		break;
	}
}