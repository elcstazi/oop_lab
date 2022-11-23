#include "ControlTeam.h"

ControlTeam::ControlTeam(CommandsMediator* mediator): mediator(mediator) {}

int ControlTeam::checkCorrectness()
{
    if (mediator->getCommandStr().length() != 4)
        return 1;

    int i = 1;
    while (i < mediator->getCommandStr().length()) {
        if (mediator->getCommandStr()[i - 1] == mediator->getCommandStr()[i])
            return 1;
        i++;
    }
    return 0;
}

void ControlTeam::handlCommands() {

    if (checkCorrectness())
        defaultCommands();

    for (int i = UP; i <= RIGHT; ++i) {
        mediator->getMapCommand().emplace(std::make_pair(eDirection(i), mediator->getCommandStr()[i - 1]));
        //commands_map.emplace(i, str_commands[i - 1]);
    }
}

void ControlTeam::defaultCommands(){
    mediator->getCommandStr() = std::string("wasd");
}
