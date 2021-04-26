//
// Created by Gandifil on 25.04.2021.
//

#include <stdexcept>
#include <iostream>
#include <parsing/ICommandParser.hpp>
#include <execution/Command.hpp>
#include <execution/CommandTypes.hpp>
#include "Machine.hpp"

int Byson::VirtualMachine::Machine::run() {
    try
    {
        while(true){
            auto command = parser->parse(std::cin);
            auto type = CommandTypes::get(command.type);
            type->run(command, state);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
