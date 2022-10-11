#include "Cell.h"

Cell::Cell() : free(SIMPLEPASSABLE), type(4) {}
Cell::Cell(kindOfCell free, int type) {
	this->free = free;
	this->type = type;
	//switch (type) {
	//case 0:// дверь
	//	break;
	//case 1:// ключ
	//	break;
	//case 2:// дамаг
	//	break;
	// case 3: 
	//case 4:// обычная клетка
	//	break;
	////case 5: 
	//}
}

int Cell::getType() {

	return type;
}

kindOfCell Cell::getFree() {

	return free;
}

