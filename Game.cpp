#include "Game.h"

void Game::gameStart() {

    srand(time(0));
    Field field;
    FieldView consoleView(&field);
    Controller controller(&field);
    Input commandReader = Input();
    while (!commandReader.getGameover()) {
        commandReader.userClicked();
    }
}