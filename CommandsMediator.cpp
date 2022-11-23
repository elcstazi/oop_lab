#include "CommandsMediator.h"

CommandsMediator::CommandsMediator(CommandsFile& file){
	str_commands = file.read();
}

void CommandsMediator::setDefaultCommands(){
    str_commands = std::string("wasd");
}


int CommandsMediator::checkCorrectness()
{
    if (str_commands.length() != 4)
        return 1;

    int i = 1;
    while (i < str_commands.length()) {
        if (str_commands[i - 1] == str_commands[i])
            return 1;
        i++;
    }
    return 0;
}

void CommandsMediator::handlCommands(){
    
    if (checkCorrectness())
        setDefaultCommands();

    commands_map.clear();
    for (int i = UP; i <= RIGHT; ++i) {
        commands_map.emplace(std::make_pair(eDirection(i), str_commands[i - 1]));
        //commands_map.emplace(i, str_commands[i - 1]);
    }
}

char CommandsMediator::getCommandUp() {
    return commands_map[UP];
}

char CommandsMediator::getCommandLeft() {
    return commands_map[LEFT];
}

char CommandsMediator::getCommandDown() {
    return commands_map[DOWN];
}

char CommandsMediator::getCommandRight() {
    return commands_map[RIGHT];
}

