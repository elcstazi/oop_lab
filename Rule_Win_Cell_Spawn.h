#pragma once
#include "Field.h"

template<size_t new_positionY, size_t new_positionX>
class Rule_Win_Cell_Spawn {
public:
    void add(Field*);
};

template<size_t new_positionY, size_t new_positionX>
void Rule_Win_Cell_Spawn<new_positionY, new_positionX>::add(Field* field){

    field->getMargin()[new_positionY][new_positionX]->setType(CELL_DOOR);
    field->getMargin()[new_positionY][new_positionX]->setEvent(new Door());
}
