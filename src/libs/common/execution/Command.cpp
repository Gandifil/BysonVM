//
// Created by Gandifil on 26.04.2021.
//

#include <sstream>
#include "Command.hpp"
#include "CommandTypes.hpp"

std::string to_string(const Byson::VirtualMachine::Command::Argument& item) {
    std::ostringstream stringStream;
    stringStream << "Argument[";
    stringStream << Byson::VirtualMachine::Command::Argument::TypeNames[item.type];
    if (item.type != Byson::VirtualMachine::Command::Argument::Null)
        stringStream << ", " << item.value;
    stringStream << "]";
    return stringStream.str();
};

std::string to_string(const Byson::VirtualMachine::Command& command) {
    std::ostringstream stringStream;
    stringStream << "Command[";
    stringStream << Byson::VirtualMachine::CommandTypes::get(command.type)->name();
    stringStream << ", ";
    stringStream << to_string(command.first);
    stringStream << ", ";
    stringStream << to_string(command.second);
    stringStream << "]";
    return stringStream.str();
};