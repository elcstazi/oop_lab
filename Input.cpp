#include "Input.h"

Input::Input(Field* field, Player* player, std::vector<Observer*>& loggers, CommandsMediator* mediator) : Controller(field, player, loggers), dir(STOP), gameover(0), mediator(mediator) {}
//Input::Input(Field* field, Player* player, std::vector<Observer*>& loggers) : Controller(field, player, loggers), dir(STOP), gameover(0) {}

void Input::userClicked() {
    dir = STOP;
    //if (_kbhit()) {
    //    switch (_getch()) {
    //    case 'w':
    //        dir = UP;
    //        break;
    //    case 'a':
    //        dir = LEFT;
    //        break;
    //    case 's':
    //        dir = DOWN;
    //        break;
    //    case 'd':
    //        dir = RIGHT;
    //        break;
    //    case 'x':
    //        gameover = 1;
    //        break;
    //    }
    //}
    //if (start(dir)) gameover = 1;
    if (_kbhit()) {
        char c = _getch();
        if (c == mediator->getCommandUp()) {
            dir = UP;
        }
        if (c == mediator->getCommandLeft()) {
            dir = LEFT;
        }
        if (c == mediator->getCommandDown()) {
            dir = DOWN;
        }
        if (c == mediator->getCommandRight()) {
            dir = RIGHT;
        }
    }
    if (start(dir)) gameover = 1;
}


int Input::getGameover() {
    return gameover;
}