#include "Controller.h"

Controller::Controller(Field* field, Player* player) {
    this->field = field;
    this->player = player;
}

int Controller::start(eDirection dir) {
    int newPositionX, newPositionY;
    int x, y, flag = 0;
    int currentX = player->getX(); // ������ �������������� ����� ������
    int currentY = player->getY();
    
    if (dir == STOP) return flag;

    else if (dir == UP) {
        newPositionY = currentY - 1;
        if (newPositionY < 0) newPositionY = field->getHeight() - 1;
        if ((field->getMargin()[newPositionY][currentX])->getType() != IMPASSABLE) {
            player->getY() = newPositionY;
        }
    }

    else if (dir == LEFT) {
        newPositionX = currentX - 1;
        if (newPositionX < 0) newPositionX = field->getWidth() - 1;
        if ((field->getMargin()[currentY][newPositionX])->getType() != IMPASSABLE) {
            player->getX() = newPositionX;
        }
    }

    else if (dir == DOWN) {
        newPositionY = currentY + 1;
        if (newPositionY > field->getHeight() - 1) newPositionY = 0;
        if ((field->getMargin()[newPositionY][currentX])->getType() != IMPASSABLE) {
            player->getY() = newPositionY;
        }
    }
    else if (dir == RIGHT) {
        newPositionX = currentX + 1;
        if (newPositionX > field->getWidth() - 1) newPositionX = 0;
        if ((field->getMargin()[currentY][newPositionX])->getType() != IMPASSABLE) {
            player->getX() = newPositionX;
        }
    }
    

    if (player->getX() != currentX || player->getY() != currentY) {
        

        if (field->getMargin()[player->getY()][player->getX()]->getType() == KEY) {         // �������������� ������ � �������, ����� ���� ����������� �� ����, ����� ����� ����� �� ������ � ������
            if (player->getNeedNumberKeys() > field->getKey() + player->getNumberKey()) {   // ������ �� ���� ����������� ���-��,  

                do {
                    y = (field->getHeight() + (rand() - rand()) % field->getHeight()) % field->getHeight();
                    x = (rand() + rand()) % field->getWidth();

                } while (field->getMargin()[y][x]->getType() != SIMPLEPASSABLE);

                field->getMargin()[y][x]->newEvent(0, new EventAddKeyOnField);  //  ���������� ������ ����� �� ����
                field->getKey()++; // ��������� ������� ���-�� ������ �� ����
            }

            field->getMargin()[player->getY()][player->getX()]->newEvent(player, new EventPlayerReceivedKey);   // ����� ����� �� ������ � ������, �������� ����, ����� ����� ������ ������
            field->getKey()--;  // ��������� ������� ���-�� ������ �� ���� 
        }


        if (player->getNeedNumberKeys() == player->getNumberKey() && player->getNumberKey()!= 0) {  // �������� ����������� ���-�� ������ � ������, ����� ��������� �����
            do {
                y = (field->getHeight() + (rand() - rand()) % field->getHeight()) % field->getHeight();
                x = (rand() + rand()) % field->getWidth();

            } while (field->getMargin()[y][x]->getType() != SIMPLEPASSABLE);    //����� ������ ������, ��� ���������� ����� �� ����

            field->getMargin()[y][x]->newEvent(player, new EventAddDoorOnField);    // ���������� ����� �� ����
        }
        

        if (field->getMargin()[player->getY()][player->getX()]->getType() == SIMPLEPASSABLE) {  // ���������� ������� � ����� �� ����, ������� ����������� � �����-�� ������������
            do {
                y = (field->getHeight() + (rand() - rand()) % field->getHeight()) % field->getHeight();
                x = (rand() + rand()) % field->getWidth();
        
            } while (field->getMargin()[y][x]->getType() != SIMPLEPASSABLE); 
            
            
            if (rand() % 7 == 0 && field->getCurrentCountTrapLoseKey() < field->getMaxCountTrapLoseKey()) { // �������, ��� �������� �� ��� ������ ����� ������ 1 ����; �� ���� ����� ��������� �����-�� ������������ ���-�� ���� ������� (2-�� �������)
                field->getMargin()[y][x]->newEvent(0, new EventAddTrapLoseKeyOnField);  // ���������� ������� �� ����
                field->getCurrentCountTrapLoseKey()++;  // ���������� �������� ���-�� ���� ������� �� ����
            }
            
            
            else if (rand() % 4 == 0 && field->getCurrentCountTrapDamage() < field->getMaxCountTrapDamage()) { // �������, ��� �������� �� ��� ������ ����� ������ 1 �����; �� ���� ����� ��������� �����-�� ������������ ���-�� ���� ������� (2-�� �������)
                field->getMargin()[y][x]->newEvent(0, new EventAddTrapTakeDamageOnField); // ���������� ������� �� ����
                field->getCurrentCountTrapDamage()++;   // ���������� �������� ���-�� ���� ������� �� ����
            }


            else if (rand() % 13 == 0 && field->getCurrentCountHeal() < field->getMaxCountHeal()) { // �����, �� ���� ����� ��������� �����-�� ������������ ���-�� ����� (2-�� �������)
                field->getMargin()[y][x]->newEvent(0, new EventAddHealOnField); // ���������� ����� �� ����
                field->getCurrentCountTrapDamage()++;   // ���������� �������� ���-�� ����� �� ����
            }

        }


        if (field->getMargin()[player->getY()][player->getX()]->getType() == DOOR) {    // ���� ����� ����� � �����, ���� �������������
            field->getMargin()[player->getY()][player->getX()]->newEvent(0, new EventPlayerInDoor);
            flag = 1;
        }


        else if (field->getMargin()[player->getY()][player->getX()]->getType() == TRAPLOSEKEY) {
            field->getMargin()[player->getY()][player->getX()]->newEvent(player, new EventTrapLoseKey); // ����� ������ ���� ���������� �������� ���-�� ����� ������� �� ����
            field->getCurrentCountTrapLoseKey()--;  // ���������� �������� ���-�� ����� ������� �� ����
        }


        else if (field->getMargin()[player->getY()][player->getX()]->getType() == TRAPDAMAGE) {
            field->getMargin()[player->getY()][player->getX()]->newEvent(player, new EventTrapTakeDamage);  // ����� ������ �����
            field->getCurrentCountTrapDamage()--;   //���������� �������� ���-�� ����� ������� �� ����
            if (player->die()) flag = 2; // ����� ������� ��� �����? ���� ������������ : ���� ������������
        }


        else if (field->getMargin()[player->getY()][player->getX()]->getType() == HEAL) {
            field->getMargin()[player->getY()][player->getX()]->newEvent(player, new EventHeal);    // ����� �������� 1 �����
            field->getCurrentCountHeal()--;   //// ���������� ���-�� ����� �� ����
        }
    }

    field->notifyUpdate();
    
    if (flag == 1) 
        std::cout << "\nPlayer win!\n\n";
    else if (flag == 2)
        std::cout << "\nA player has died!\n\n";
    else {
        std::cout << "\n\nhealth: " << player->getHealth() << "\nnumber key: " << player->getNumberKey() << "\nneed to collect key: " << player->getNeedNumberKeys() - player->getNumberKey() << '\n';
        //std::cout << "\n\nhealth: " << player->gethealth() << "\nnumber key: " << player->getNumberKey() << "\nneed to collect key: " << player->getNeedNumberKeys() << '\n';
    }
    return flag;
}