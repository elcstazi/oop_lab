#include "CommandsMediator.h"
#include "ControlTeam.h"

void CommandsMediator::set_comands_handler(ControlTeam* newControlTeam){
    controlCommand = newControlTeam;
}

void CommandsMediator::set_comands(std::string new_commands){
    str_commands = new_commands;
}

void CommandsMediator::handle_comands(){
    controlCommand->handlCommands();
}

std::map<int, char>& CommandsMediator::getMapCommand(){
    return commands_map;
}

std::string& CommandsMediator::getCommandStr()
{
    return str_commands;
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

