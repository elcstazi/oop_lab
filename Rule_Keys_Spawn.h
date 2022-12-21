#pragma once
#pragma once
#include "Field.h"

template<size_t number>
class Rule_Keys_Spawn {
public:
    void add(Field*);
    void add_keys(Field*);
};

template<size_t number>
void Rule_Keys_Spawn<number>::add(Field* field)
{
    for (int k = 0; k < number; k++) {
        add_keys(field);
    }
}

template<size_t number>
void Rule_Keys_Spawn<number>::add_keys(Field* field) {
    std::pair <int, int> found_position_cell = field->find_empty_cell();
    field->getMargin()[found_position_cell.first][found_position_cell.second]->setType(CELL_KEY);
    field->getMargin()[found_position_cell.first][found_position_cell.second]->setEvent(new Key());
}