#include "Cell.h"


Cell::Cell() : free(SIMPLEPASSABLE), type(4), event(0) {}
Cell::Cell(kindOfCell free, int type) {
	this->free = free;
	this->type = type;
	event = 0;
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


void Cell::setType(int type) {
	this->type = type;
}


kindOfCell Cell::getFree() {

	return free;
}


void Cell::playerHere() {}