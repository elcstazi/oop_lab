#pragma once
#include "Field.h"

template<size_t new_positionY, size_t new_positionX>
class Rule_Hero_Spawn {

public:
	void add(Field*);

};

template<size_t new_positionY, size_t new_positionX>
void Rule_Hero_Spawn<new_positionY, new_positionX>::add(Field* field) {
	field->getCurrentX() = new_positionX;
	field->getCurrentY() = new_positionY;
}