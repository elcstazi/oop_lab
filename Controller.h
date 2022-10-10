#pragma once
#include "Field.h"
#include "Player.h"
#include "Component.h"

class Controller : public Component {

	Field* field;
	Player* player;
public:
	Controller(Field*);
	//Controller(Mediator*, Field*);
	//Controller(Mediator*);
	void start(eDirection);
};