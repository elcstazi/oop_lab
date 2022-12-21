#pragma once
#include "Field.h"

template<size_t number>
class Rule_Traps_Spawn {
public:
    void add(Field*);
    void add_trap(Field*);
};

template<size_t number>
void Rule_Traps_Spawn<number>::add(Field* field)
{
    for (int k = 0; k < number; k++) {
        add_trap(field);
    }
}

template<size_t number>
void Rule_Traps_Spawn<number>::add_trap(Field* field) {
    std::pair <int, int> found_position_cell = field->find_empty_cell();
    field->getMargin()[found_position_cell.first][found_position_cell.second]->setType(TRAPDAMAGE);
    field->getMargin()[found_position_cell.first][found_position_cell.second]->setEvent(new TrapDamage());
}