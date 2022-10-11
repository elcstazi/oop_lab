#pragma once
#include <iostream>
#include <windows.h>
#include "Field.h"
#include "CellView.h"
#include "Observer.h"

class Field;

class FieldView : public Observer{
	CellView* cellView;
	Field* field;
public:
	FieldView(Field*);
	void update();
	void drawHorizontalBorder(int);
};