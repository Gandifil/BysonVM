//
// Created by Gandifil on 25.04.2021.
//

#ifndef BYSONVM_ICOMMANDPARSER_HPP
#define BYSONVM_ICOMMANDPARSER_HPP


#include <fstream>
#include "execution/Command.hpp"

namespace Byson::VirtualMachine {
    class ICommandParser {
    public:
        virtual ~ICommandParser() = default;

        virtual Command parse(std::istream& stream) = 0;
    };
}


#endif //BYSONVM_ICOMMANDPARSER_HPP
