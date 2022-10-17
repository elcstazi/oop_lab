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
	Player* player;// ����� ������� ������ � ������� ���������� � ����, ������ ��� ����������� ����� ����, ��� ������ �������� � ���� ��������� ���������� ����
public:
	Controller(Field*, Player*);
	int start(eDirection);
};