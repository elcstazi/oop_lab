#pragma once
#include "Field.h"
#include "FieldView.h"
#include "Observable.h"


//#include "Door.h"

//class Field;

class Controller: Observable {
	Field* field;
	Player* player;
	FieldView* fieldView;
public:
	Controller(Field*, Player*, std::vector<Observer*>&);
	int start(eDirection);
	void processEvent();

};