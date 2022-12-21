#pragma once
#include "Field.h"

template<size_t number>
class Rule_Heals_Spawn {
public:
	void add(Field*);
	void add_heal(Field*);
};

template<size_t number>
void Rule_Heals_Spawn<number>::add(Field* field) {
	for (int i = 0; i < number; i++) {
		add_heal(field);
	}
}

template<size_t number>
void Rule_Heals_Spawn<number>::add_heal(Field* field) {
	std::pair <int, int> found_position_cell = field->find_empty_cell();
	field->getMargin()[found_position_cell.first][found_position_cell.second]->setType(HEAL);
	field->getMargin()[found_position_cell.first][found_position_cell.second]->setEvent(new Heal());
}