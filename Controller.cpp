#include "Controller.h"

Controller::Controller(Field* field, Player* player, std::vector<Observer*>& loggers) {
    this->field = field;
    this->player = player;
    this->fieldView = new FieldView(field);
    fieldView->update();

    for (auto cur : loggers)
        addObserver(cur);
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
    else
        Notify("the player tried to move to the impassable cell", "Controller", WARN);



    fieldView->update();


    if (player->getPlayerInDoor()) {
        std::cout << "\nPlayer win!\n\n";
        Notify("player walks through the door and wins", "Controller", INFO);
        return 1;
    }
    else if (player->die()) {
        std::cout << "\nA player has died!\n\n";
        Notify("the player loses", "Controller", INFO);
        return 1;
    }
    else {
        std::cout << "\n\nhealth: " << player->getHealth() << "\nnumber key: " << player->getNumberKey() << "\nneed to collect key: " << player->getNeedNumberKeys() - player->getNumberKey() << "\n\n";

        for (auto cur : observers)
            cur->print();
    }
    return 0;
}

void Controller::processEvent() {

    if (field->getMargin()[player->getY()][player->getX()]->getEvent()) {
        std::string resCurrentEvent = field->getMargin()[player->getY()][player->getX()]->getEvent()->trigger(player, field);
        if (resCurrentEvent != std::to_string(1))
            Notify("an event occurred", resCurrentEvent, INFO);
    }
}