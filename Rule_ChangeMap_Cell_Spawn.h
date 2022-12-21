#pragma once
#pragma once
#include "Field.h"

template<size_t number>
class Rule_ChangeMap_Cell_Spawn {
public:
    void add(Field*);
    void add_cell_map_change(Field*);
};

template<size_t number>
void Rule_ChangeMap_Cell_Spawn<number>::add(Field* field)
{
    for (int k = 0; k < number; k++) {
        add_cell_map_change(field);
    }
}

template<size_t number>
void Rule_ChangeMap_Cell_Spawn<number>::add_cell_map_change(Field* field) {
    std::pair <int, int> found_position_cell = field->find_empty_cell();
    field->getMargin()[found_position_cell.first][found_position_cell.second]->setType(MAPCHANGE);
    field->getMargin()[found_position_cell.first][found_position_cell.second]->setEvent(new MapChange());
}