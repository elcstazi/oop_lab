#include "Controller.h"

Controller::Controller(Field* field, Player* player) {
    this->field = field;
    this->player = player;
}

int Controller::start(eDirection dir) {
    int newPositionX, newPositionY;
    int x, y, flag = 0;
    int currentX = player->getX(); // теперь взаимодействие через игрока
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
        

        if (field->getMargin()[player->getY()][player->getX()]->getType() == KEY) {         // взаимодействие игрока с ключами, новый ключ довабляется на поле, когда игрок зашел на клетку с ключем
            if (player->getNeedNumberKeys() > field->getKey() + player->getNumberKey()) {   // ключей на поле определенно кол-во,  

                do {
                    y = (field->getHeight() + (rand() - rand()) % field->getHeight()) % field->getHeight();
                    x = (rand() + rand()) % field->getWidth();

                } while (field->getMargin()[y][x]->getType() != SIMPLEPASSABLE);

                field->getMargin()[y][x]->newEvent(0, new EventAddKeyOnField);  //  добавление нового ключа на поле
                field->getKey()++; // увеличить текущее кол-во ключей на поле
            }

            field->getMargin()[player->getY()][player->getX()]->newEvent(player, new EventPlayerReceivedKey);   // игрок стоит на клетке с ключем, получает ключ, после этого клетка пустая
            field->getKey()--;  // уменьшить текущее кол-во ключей на поле 
        }


        if (player->getNeedNumberKeys() == player->getNumberKey() && player->getNumberKey()!= 0) {  // проверяю достаточное кол-во ключей у игрока, чтобы открылась дверь
            do {
                y = (field->getHeight() + (rand() - rand()) % field->getHeight()) % field->getHeight();
                x = (rand() + rand()) % field->getWidth();

            } while (field->getMargin()[y][x]->getType() != SIMPLEPASSABLE);    //поиск пустой клетки, для добавления двери на поле

            field->getMargin()[y][x]->newEvent(player, new EventAddDoorOnField);    // добавление двери на поле
        }
        

        if (field->getMargin()[player->getY()][player->getX()]->getType() == SIMPLEPASSABLE) {  // добавление ловушек и хилок на поле, событие срабатывает с какой-то вероятностью
            do {
                y = (field->getHeight() + (rand() - rand()) % field->getHeight()) % field->getHeight();
                x = (rand() + rand()) % field->getWidth();
        
            } while (field->getMargin()[y][x]->getType() != SIMPLEPASSABLE); 
            
            
            if (rand() % 7 == 0 && field->getCurrentCountTrapLoseKey() < field->getMaxCountTrapLoseKey()) { // ловушка, при переходе на эту клетку игрок теряет 1 ключ; на поле может находится какое-то максимальное кол-во этих ловушек (2-ое условие)
                field->getMargin()[y][x]->newEvent(0, new EventAddTrapLoseKeyOnField);  // довабление ловушки на поле
                field->getCurrentCountTrapLoseKey()++;  // увеличение текущего кол-ва этих ловушке на поле
            }
            
            
            else if (rand() % 4 == 0 && field->getCurrentCountTrapDamage() < field->getMaxCountTrapDamage()) { // ловушка, при переходе на эту клетку игрок теряет 1 жизнь; на поле может находится какое-то максимальное кол-во этих ловушек (2-ое условие)
                field->getMargin()[y][x]->newEvent(0, new EventAddTrapTakeDamageOnField); // довабление ловушки на поле
                field->getCurrentCountTrapDamage()++;   // увеличение текущего кол-ва этих ловушке на поле
            }


            else if (rand() % 13 == 0 && field->getCurrentCountHeal() < field->getMaxCountHeal()) { // хилка, на поле может находится какое-то максимальное кол-во хилок (2-ое условие)
                field->getMargin()[y][x]->newEvent(0, new EventAddHealOnField); // довабление хилки на поле
                field->getCurrentCountTrapDamage()++;   // увеличение текущего кол-ва хилок на поле
            }

        }


        if (field->getMargin()[player->getY()][player->getX()]->getType() == DOOR) {    // если игрок зашел в дверь, игра заканчивается
            field->getMargin()[player->getY()][player->getX()]->newEvent(0, new EventPlayerInDoor);
            flag = 1;
        }


        else if (field->getMargin()[player->getY()][player->getX()]->getType() == TRAPLOSEKEY) {
            field->getMargin()[player->getY()][player->getX()]->newEvent(player, new EventTrapLoseKey); // игрок теряет ключ уменьшение текущего кол-ва таких ловушек на поле
            field->getCurrentCountTrapLoseKey()--;  // уменьшение текущего кол-ва таких ловушек на поле
        }


        else if (field->getMargin()[player->getY()][player->getX()]->getType() == TRAPDAMAGE) {
            field->getMargin()[player->getY()][player->getX()]->newEvent(player, new EventTrapTakeDamage);  // игрок теряет жизнь
            field->getCurrentCountTrapDamage()--;   //уменьшение текущего кол-ва таких ловушек на поле
            if (player->die()) flag = 2; // игрок потерял все жизни? игра заканчиваеся : игра продолжается
        }


        else if (field->getMargin()[player->getY()][player->getX()]->getType() == HEAL) {
            field->getMargin()[player->getY()][player->getX()]->newEvent(player, new EventHeal);    // игрок получает 1 жизнь
            field->getCurrentCountHeal()--;   //// уменьшение кол-ва хилок на поле
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