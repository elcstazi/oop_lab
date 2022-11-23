#include "Game.h"
void Game::gameStart() {

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
    
    
    srand(time(0));
    Player player;
    Field field(height, width);
    
    for (auto cur : loggers)
        player.addObserver(cur);
    
    
    field.updatePlayer(&player);
    CommandsFile file;
    CommandsMediator mediator(file);
    mediator.handlCommands();
     Input input(&field, &player, loggers, &mediator);
    //Input input(&field, &player, loggers);
    
    for (auto cur : loggers)
        cur->print();
    
    
    while (!input.getGameover()) {
        input.userClicked();
    }
    
    for (auto cur : loggers){
        cur->Update("The game ended", "Game", WARN);
        cur->print();
    }
    //CommandsFile file;
    //CommandsMediator mediator(file);
    //mediator.handlCommands();
}