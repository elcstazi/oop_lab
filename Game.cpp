#include "Game.h"

void Game::gameStart() {
    srand(time(0));
    Player player;
    Field field;
    field.updatePlayer(&player);
    FieldView fieldView(&field);
    Input input(&field, &player);
    fieldView.update();
    while (!input.getGameover()) {
        input.userClicked();
    }
}