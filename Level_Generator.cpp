#include "Level_Generator.h"

Field Level_Generator::select_level(int& height, int& width, int&level)
{

	switch (level) {
	case 1:
		Field_Generator<Rule_Hero_Spawn<1, 1>, Rule_Traps_Spawn<30>, Rule_Heals_Spawn<39>, Rule_ChangeMap_Cell_Spawn<20>, Rule_Keys_Spawn<10>, Rule_Walls_Spawn<50>, Rule_Win_Cell_Spawn<10,10>> rule_1;
		return rule_1.FieldGenerate(height, width);
		
	case 2:
		Field_Generator<Rule_Hero_Spawn<2, 2>, Rule_Traps_Spawn<30>, Rule_Heals_Spawn<39>, Rule_ChangeMap_Cell_Spawn<20>, Rule_Keys_Spawn<10>, Rule_Walls_Spawn<50>, Rule_Win_Cell_Spawn<5, 1>> rule_2;
		return rule_2.FieldGenerate(height, width);
	
	case 3:
		Field_Generator<Rule_Hero_Spawn<3, 3>, Rule_Traps_Spawn<15>, Rule_Heals_Spawn<25>, Rule_ChangeMap_Cell_Spawn<40>, Rule_Keys_Spawn<15>, Rule_Walls_Spawn<50>, Rule_Win_Cell_Spawn<13, 21>> rule_3;
		return rule_3.FieldGenerate(height, width);
	
	default:
		Field_Generator<Rule_Hero_Spawn<4, 4>, Rule_Traps_Spawn<25>, Rule_Heals_Spawn<25>, Rule_ChangeMap_Cell_Spawn<40>, Rule_Keys_Spawn<5>, Rule_Walls_Spawn<60>, Rule_Win_Cell_Spawn<1, 5>> rule_4;
		return rule_4.FieldGenerate(height, width);
		
	}
}
