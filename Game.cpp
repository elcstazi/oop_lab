#include "Game.h"
void Game::gameStart() {
    
    int level;
    int logTo;
    std::cout << "Select the tracking level\nlevels:\n0 - WARN\n1 - INFO\n2 - TRACE\n3 - ALL\n";
    std::cin >> level;
    std::cout << "Choose how to output the logs\nWays:\n0 - no logging\n1 - output to the console\n2 - output to file\n3- output to console and file\n";
    std::cin >> logTo;
    Logger log((logLevel)level, (typesLogMethods)logTo);
    
    srand(time(0));
    Player player;
    Field field;
    field.updatePlayer(&player);
    Input input(&field, &player);


    player.addObserver(&log);
    field.addObserver(&log);


    while (!input.getGameover()) {
        input.userClicked();
    }
}