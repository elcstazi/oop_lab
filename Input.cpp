#include "Input.h"
#include "Controller.h"

Input::Input() : gameover(1) {}
void Input::userClicked() {
    dir = STOP;
    if (_kbhit) {
        switch (_getch()) {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
    mediator->notify(dir);
}

int Input::getGameover() {
    return gameover;
}
//Input::Input(Mediator* mediator) : Component(mediator) {}