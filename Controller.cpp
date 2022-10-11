#include "Controller.h"

Controller::Controller(Field* field) {
    this->field = field;
}

void Controller::start(eDirection dir) {
    int newPositionX, newPositionY;
    int currentX = field->getCurrentX();
    int currentY = field->getCurrentY();

    if (dir == UP) {
        newPositionY = currentY - 1;
        if (newPositionY < 0) newPositionY = field->getHeight() - 1;
        if ((field->getMargin()[newPositionY][currentX])->getFree() != IMPASSABLE) {
            field->setCurrentY(newPositionY);
        }
    }

    else if (dir == LEFT) {
        newPositionX = currentX - 1;
        if (newPositionX < 0) newPositionX = field->getWidth() - 1;
        if ((field->getMargin()[currentY][newPositionX])->getFree() != IMPASSABLE) {
            field->setCurrentX(newPositionX);
        }
    }

    else if (dir == DOWN) {
        newPositionY = currentY + 1;
        if (newPositionY > field->getHeight() - 1) newPositionY = 0;
        if ((field->getMargin()[newPositionY][currentX])->getFree() != IMPASSABLE) {
            field->setCurrentY(newPositionY);
        }
    }
    else if (dir == RIGHT) {
        newPositionX = currentX + 1;
        if (newPositionX > field->getWidth() - 1) newPositionX = 0;
        if ((field->getMargin()[currentY][newPositionX])->getFree() != IMPASSABLE) {
            field->setCurrentX(newPositionX);
        }
    }
}