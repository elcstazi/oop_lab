#include "Game.h"
void Game::gameStart() {

    srand(time(nullptr));

    int level;
    int logTo;
    std::vector<Observer*> loggers;
    std::cout << "Select the tracking level\nlevels:\n0 - WARN\n1 - INFO\n2 - TRACE\n3 - ALL\n";
    std::cin >> level;
    std::cout << "Choose how to output the logs\nWays:\n0 - no logging\n1 - output to the console\n2 - output to file\n3- output to console and file\n";
    std::cin >> logTo;
    
    if ((typesLogMethods)logTo == CONSOLE_LOG || (typesLogMethods)logTo == CONSOLE_AND_FILE_LOG)
        loggers.push_back(new LogToConsole((logLevel)level));
    
    if ((typesLogMethods)logTo == FILE_LOG || (typesLogMethods)logTo == CONSOLE_AND_FILE_LOG)
        loggers.push_back(new LogToFile((logLevel)level));
    
    
    int height, width;
    
    std::cout << "enter the height\n";
    std::cin >> height;
    std::cout << "enter the width\n";
    std::cin >> width;
    
    if (height <= 0 || width <= 0) {
        for (auto cur : loggers) 
            cur->Update("incorrectly entered field parameters, the height and width will be taken by default", "Game", WARN);
    }
    
    for (auto cur : loggers) 
        cur->Update("the game started", "Game", TRACE);
    
    
    Player player;
    Level_Generator lv;

    int level_game;
    std::cout << "Select a level.\nAvailable levels - 1, 2, 3\n";
    std::cin >> level_game;
    Field field = lv.select_level(height, width, level_game);
   
    
    for (auto cur : loggers)
        player.addObserver(cur);
    
    
    field.updatePlayer(&player);
    CommandsMediator mediator;
    InputFile file(&mediator);
    file.read();
    ControlTeam comandHandle(&mediator);
    mediator.handle_comands();
    Input input(&field, &player, loggers, &mediator);
    
    for (auto cur : loggers)
        cur->print();
    
    
    while (!input.getGameover()) {
        input.userClicked();
    }
    
    for (auto cur : loggers){
        cur->Update("The game ended", "Game", WARN);
        cur->print();
    }
}