#pragma once
#include <iostream>
#include <windows.h>
#include "Field.h"
#include "CellView.h"


class FieldView {
	CellView* cellView;
	Field* field;
public:
	FieldView(Field*);
	void update();
	void drawHorizontalBorder(int);
};