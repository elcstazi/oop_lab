#include "Cell.h"

Cell::Cell() : free(SIMPLEPASSABLE), type(4) {}
Cell::Cell(kindOfCell free, int type) {
	this->free = free;
	this->type = type;
	//switch (type) {
	//case 0:// �����
	//	break;
	//case 1:// ����
	//	break;
	//case 2:// �����
	//	break;
	// case 3: 
	//case 4:// ������� ������
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

