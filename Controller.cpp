#include "Controller.h"

Controller::Controller(Field* field, Player* player) {
    this->field = field;
    this->player = player;
    this->fieldView = new FieldView(field);
    fieldView->update();
}

int Controller::start(eDirection dir) {
    int newPositionX, newPositionY;
    int currentX = player->getX();
    int currentY = player->getY();

    if (dir == STOP) return 0;

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
    
    if (currentX != player->getX() || currentY != player->getY())
        processEvent();

    

    fieldView->update();
    
    if (player->win()) {
        std::cout << "\nPlayer win!\n\n";
        return 1;
    }
    else if (player->die()) {
        std::cout << "\nA player has died!\n\n";
        return 1;
    }
    else
        std::cout << "\n\nhealth: " << player->getHealth() << "\nnumber key: " << player->getNumberKey() << "\nneed to collect key: " << player->getNeedNumberKeys() - player->getNumberKey() << '\n';
    //else if (player->die())
    //    std::cout << "\nA player has died!\n\n";
    //else {
    //   // std::cout << "\n\nhealth: " << player->getHealth() << "\nnumber key: " << player->getNumberKey() << "\nneed to collect key: " << player->getNeedNumberKeys() - player->getNumberKey() << '\n';
    //    if (player->getNeedNumberKeys() != player->getNumberKey())
    //    std::cout << "\n\nhealth: " << player->getHealth() << "\nYou need to collect " << player->getNeedNumberKeys() << " keys. The number of keys collected: " << player->getNumberKey() << '\n';
    //    else
    //    std::cout << "\n\nhealth: " << player->getHealth() << "\nyou have collected the required number of keys, get to the door" << '\n';
    //}
    return 0;
}

void Controller::processEvent() {
   
    if (field->getMargin()[player->getY()][player->getX()]->getEvent()) {
        //if (field->getMargin()[player->getY()][player->getX()]->getEvent()->trigger(player, field)) {
        //    field->getMargin()[player->getY()][player->getX()]->setEvent(0);
        //    field->getMargin()[player->getY()][player->getX()]->setType(SIMPLEPASSABLE);
        //
        //}
        field->getMargin()[player->getY()][player->getX()]->getEvent()->trigger(player, field);
    }
}