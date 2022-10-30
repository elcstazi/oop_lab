#include "Game.h"
void Game::gameStart() {
    srand(time(0));
    Player player;
    Field field;
    field.updatePlayer(&player);
    Input input(&field, &player);
    while (!input.getGameover()) {
        input.userClicked();
    }
}