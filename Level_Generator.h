#pragma once
#include <iostream>
#include "Field.h"
#include "Rule_ChangeMap_Cell_Spawn.h"
#include "Rule_Heals_Spawn.h"
#include "Rule_Hero_Spawn.h"
#include "Rule_Keys_Spawn.h"
#include "Rule_Walls_Spawn.h"
#include "Rule_Win_Cell_Spawn.h"
#include "Rule_Traps_Spawn.h"
#include "Field_Generator.h"

class Level_Generator {

public:

	Field select_level(int&, int&, int&);
};