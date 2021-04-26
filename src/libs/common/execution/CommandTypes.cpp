//
// Created by Gandifil on 26.04.2021.
//

#include "CommandTypes.hpp"

const char *Byson::VirtualMachine::EmptyCommand::name() {
    return "empty";
}

bool Byson::VirtualMachine::EmptyCommand::isValid(const Byson::VirtualMachine::Command &command) {
    return true;
}

void Byson::VirtualMachine::EmptyCommand::run(const Command &command, State &state) const {}

const char *Byson::VirtualMachine::AllocateCommand::name() {
    return "allocate";
}

bool Byson::VirtualMachine::AllocateCommand::isValid(const Byson::VirtualMachine::Command &command) {
    return true;
}

void Byson::VirtualMachine::AllocateCommand::run(const Command &command, State &state) const {}

const char *Byson::VirtualMachine::FreeCommand::name() {
    return "free";
}

bool Byson::VirtualMachine::FreeCommand::isValid(const Byson::VirtualMachine::Command &command) {
    return true;
}

void Byson::VirtualMachine::FreeCommand::run(const Command &command, State &state) const {}

const char *Byson::VirtualMachine::PrintCommand::name() {
    return "print";
}

bool Byson::VirtualMachine::PrintCommand::isValid(const Byson::VirtualMachine::Command &command) {
    return true;
}

void Byson::VirtualMachine::PrintCommand::run(const Command &command, State &state) const {

}

