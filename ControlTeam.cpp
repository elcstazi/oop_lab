#include "ControlTeam.h"

ControlTeam::ControlTeam(CommandsMediator* mediator) {
    this->mediator = mediator;
    mediator->set_comands_handler(this);
}

int ControlTeam::checkCorrectness()
{
    if (mediator->getCommandStr().length() != 4)
        return 0;

    int i = 1;
    while (i < mediator->getCommandStr().length()) {
        if (mediator->getCommandStr()[i - 1] == mediator->getCommandStr()[i])
            return 0;
        i++;
    }
    return 1;
}

std::map<char, int> ControlTeam::handlCommands() {

    std::map<char, int> commands_map;
    std::string str_comands = mediator->getCommandStr();

    if (!checkCorrectness())
        str_comands = defaultCommands();

    for (int i = UP; i <= RIGHT; ++i) {
        commands_map.emplace(str_comands[i - 1], i);
    }
    return commands_map;
}

std::string ControlTeam::defaultCommands(){
    return std::string("wasd");
}
