//
// Created by Gandifil on 26.04.2021.
//

#ifndef BYSONVM_MACHINE_HPP
#define BYSONVM_MACHINE_HPP

#include <memory>
#include "State.hpp"

namespace Byson::VirtualMachine {
    class ICommandParser;

    class Machine {
    public:
        explicit Machine(ICommandParser* parser) : parser{ parser }{}

        int run();

    private:
        std::unique_ptr<ICommandParser> parser;
        State state;
    };
}

#endif //BYSONVM_MACHINE_HPP
