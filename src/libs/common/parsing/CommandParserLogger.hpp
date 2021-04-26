//
// Created by Gandifil on 25.04.2021.
//

#ifndef BYSONVM_COMMANDPARSERLOGGER_HPP
#define BYSONVM_COMMANDPARSERLOGGER_HPP

#include <iostream>
#include <memory>
#include "ICommandParser.hpp"

namespace Byson::VirtualMachine {
    class CommandParserLogger: public ICommandParser {
    public:
        explicit CommandParserLogger(ICommandParser* parser): parser{ parser }{}
        ~CommandParserLogger() override = default;

        Command parse(std::istream &stream) override {
            auto result = parser->parse(stream);
            std::cout << "Parsed:\t" << to_string(result) << std::endl;
            return result;
        }

    private:
        std::unique_ptr<ICommandParser> parser;
    };
}

#endif //BYSONVM_COMMANDPARSERLOGGER_HPP
