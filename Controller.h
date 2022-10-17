#pragma once
#include "Field.h"
#include "EventPlayerReceivedKey.h"
#include "EventAddKeyOnField.h"
#include "EventAddDoorOnField.h"
#include "EventPlayerInDoor.h"
#include "EventTrapLoseKey.h"
#include "EventAddTrapLoseKeyOnField.h"
#include "EventAddTrapTakeDamageOnField.h"
#include "EventTrapTakeDamage.h"
#include "EventHeal.h"
#include "EventAddHealOnField.h"


class Controller {
	Field* field;
	Player* player;// мен€ю позицию игрока и вызываю обновление у пол€, раньше все происходило через поле, при вызове сеттеров у пол€ вызыволсь обновление пол€
public:
	Controller(Field*, Player*);
	int start(eDirection);
};