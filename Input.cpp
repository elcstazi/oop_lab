#include "Input.h"

Input::Input(Field* field) : Controller(field) {}

void Input::userClicked() {
    dir = STOP;
    if (_kbhit()) {
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
    start(dir);
}