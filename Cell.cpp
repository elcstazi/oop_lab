#include "Cell.h"

Cell::Cell() : Free(SIMPLEPASSABLE), type(4), cellEvent(0) {}
Cell::Cell(kindOfCell free, int type) : Free(free) {
	this->type = type;
	cellEvent = 0;
	//switch (type) {
	//case 0://�����(������������ �������)
	//	break;
	//case 1://����
	//	break;
	//case 2://�������, + �����
	//	break;
	// case 3: �����, - �����
	//case 4:// ������� ������
	//	break;
	////case 5: �����
	//}
}

int Cell::getType() {

	return type;
}

kindOfCell Cell::getFree() {

	return Free;
}
