#pragma once
#include "Field.h"

class Controller {
	Field* field;
public:
	Controller(Field*);
	void start(eDirection);
};