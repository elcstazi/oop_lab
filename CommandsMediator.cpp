#include "CommandsMediator.h"
#include "ControlTeam.h"

void CommandsMediator::set_comands_handler(ControlTeam* newControlTeam){
    controlCommand = newControlTeam;
}

void CommandsMediator::set_comands(std::string new_commands){
    str_commands = new_commands;
}

void CommandsMediator::handle_comands(){
    commands_map = controlCommand->handlCommands();
}

std::map<char, int>& CommandsMediator::getMapCommand(){
    return commands_map;
}

std::string& CommandsMediator::getCommandStr()
{
    return str_commands;
}


eDirection CommandsMediator::getCurrentCommand(char currentCommand) {
    return eDirection(commands_map[currentCommand]);
}


