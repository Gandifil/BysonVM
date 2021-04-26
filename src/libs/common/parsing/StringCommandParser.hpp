//
// Created by Gandifil on 25.04.2021.
//

#ifndef BYSONVM_STRINGCOMMANDPARSER_HPP
#define BYSONVM_STRINGCOMMANDPARSER_HPP

#include <map>
#include <sstream>
#include "ICommandParser.hpp"
#include "../execution/CommandTypes.hpp"

namespace Byson::VirtualMachine {
    class StringCommandParser: public ICommandParser {
    public:
        StringCommandParser(){
            int i = 0;
            for(auto& type: CommandTypes::types)
                types[type->name()] = static_cast<Command::TypeID>(i++);
        }

        ~StringCommandParser() override = default;

        Command parse(std::istream &stream) override {
            std::string line;

            if (getline(stream, line))
                return parse(line);
            else throw std::invalid_argument{ "Command line hasn't a type name" };
        }

    private:
        Command::Argument parseArg(const std::string& line) {
            Command::Argument result{};
            if (line[0] == '#'){
                result.type = Command::Argument::Index;
                result.value = std::stoi(line.substr(1));
            }
            else {
                result.type = Command::Argument::Integer;
                result.value = std::stoi(line);
            }
            return result;
        }

        Command parse(const std::string& line) {
            Command result{};
            std::istringstream lineStream(line);

            std::string buffer;
            if (getline(lineStream, buffer, ' ')){
                std::transform(buffer.begin(), buffer.end(), buffer.begin(), tolower);
                result.type = types.at(buffer);
            }
            else throw std::invalid_argument{ "Command line hasn't a type name" };

            if (getline(lineStream, buffer, ' ')) {
                result.first = parseArg(buffer);

                if (getline(lineStream, buffer, ' '))
                    result.second = parseArg(buffer);
            }

            return result;
        }

        std::map<std::string, Command::TypeID> types;
    };

}


#endif //BYSONVM_STRINGCOMMANDPARSER_HPP
