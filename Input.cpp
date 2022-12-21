#include "Input.h"

Input::Input(Field* field, Player* player, std::vector<Observer*>& loggers, CommandsMediator* mediator) : Controller(field, player, loggers), dir(STOP), gameover(0), mediator(mediator) {}

void Input::userClicked() {
    dir = STOP;
    if (_kbhit()) {
        char c = _getch();
        dir = mediator->getCurrentCommand(c);
    }
    if (start(dir)) gameover = 1;
}


int Input::getGameover() {
    return gameover;
}