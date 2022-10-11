#include "Game.h"

void Game::gameStart() {
    srand(time(0));
    Field field;
    FieldView fieldView(&field);
    Input input(&field);
    fieldView.update();
    while (1) {
        input.userClicked();
    }
}