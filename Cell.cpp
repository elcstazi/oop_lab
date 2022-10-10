#include "Cell.h"

Cell::Cell() : Free(SIMPLEPASSABLE), type(4), cellEvent(0) {}
Cell::Cell(kindOfCell free, int type) : Free(free) {
	this->type = type;
	cellEvent = 0;
	//switch (type) {
	//case 0://дверь(пользователь выиграл)
	//	break;
	//case 1://ключ
	//	break;
	//case 2://элексир, + жизнь
	//	break;
	// case 3: дамаг, - жизнь
	//case 4:// обычная клетка
	//	break;
	////case 5: стена
	//}
}

int Cell::getType() {

	return type;
}

kindOfCell Cell::getFree() {

	return Free;
}
