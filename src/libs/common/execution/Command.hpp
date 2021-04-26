//
// Created by Gandifil on 25.04.2021.
//

#ifndef BYSONVM_COMMAND_HPP
#define BYSONVM_COMMAND_HPP

#include <string>
#include <State.hpp>

namespace Byson::VirtualMachine {
    struct Command {
    public:
        class Argument {
        public:
            enum Type{
                Null,
                Index,
                Integer,
            };

            inline static char *TypeNames[] = {
                "Null",
                "Index",
                "Integer",
            };

            Type type;
            int value;

            int calcValue(const State& state) const {
                switch (type) {
                    case Index:
                        return state.heap[value];
                        break;

                    case Integer:
                        return value;
                        break;

                    case Null:
                    default:
                        return 0;
                }
            }
        };

        class Type {
        public:
            virtual const char* name() = 0;

            virtual bool isValid(const Command& command) = 0;

            virtual void run(const Command &command, State &state) const = 0;
        };

        enum TypeID{
            Empty,
            CreateIndexedVariable,
            SetIndexedVariable,
            PrintIndexedVariable,
        };

        TypeID type;
        Argument first;
        Argument second;
    };
}

std::string to_string(const Byson::VirtualMachine::Command::Argument& item);

std::string to_string(const Byson::VirtualMachine::Command& command);

#endif //BYSONVM_COMMAND_HPP
