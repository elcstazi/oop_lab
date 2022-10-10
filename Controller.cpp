#include "Controller.h"

//Controller::Controller(Mediator* dialog, Field* field) : Component(dialog), field(field) {}
Controller::Controller(Field* field) : field(field) {}

//Controller::Controller(Mediator* dialog) : Controller(dialog) {}

void Controller::start(eDirection  dir) {
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



   //if (field->getMargin()[currentY][currentX]->getFree() == SIMPLEPASSABLE && field->getMargin()[currentY][currentX]->getType() == 1) {
   //    field->addKey();
   //}
   //if (field->getNumberKeys() == field->getPlayerNumberkeys() && !field->getNumberDoor()) {
   //    field->addDoor();
   //    field->getNumberDoor() = 1;
   //}
   //field->getMargin()[currentY][currentX]->playerHere(field->getPlayer());
}