#pragma once
#include "Field.h"
#include "FieldView.h"
#include "Types.h"
//#include "Door.h"

//class Field;

class Controller {
	Field* field;
	Player* player;
	FieldView* fieldView;
public:
	Controller(Field*, Player*);
	int start(eDirection);
	void processEvent();

};