//
// Created by Gandifil on 26.04.2021.
//

#ifndef BYSONVM_COMMANDTYPES_HPP
#define BYSONVM_COMMANDTYPES_HPP

#include "Command.hpp"

namespace Byson::VirtualMachine {
    class EmptyCommand: public Command::Type {
    public:
        const char *name() override;

        bool isValid(const Command &command) override;

        void run(const Command &command, State &state) const override;
    };

    class AllocateCommand: public Command::Type {
    public:
        const char *name() override;

        bool isValid(const Command &command) override;

        void run(const Command &command, State &state) const override;
    };

    class FreeCommand: public Command::Type {
    public:
        const char *name() override;

        bool isValid(const Command &command) override;

        void run(const Command &command, State &state) const override;
    };

    class PrintCommand: public Command::Type {
    public:
        const char *name() override;

        bool isValid(const Command &command) override;

        void run(const Command &command, State &state) const override;
    };

    class CommandTypes {
    public:
        inline static Command::Type* types[] = {
                new EmptyCommand{},
                new AllocateCommand{},
                new FreeCommand{},
                new PrintCommand{},
        };

        static Command::Type* get(Command::TypeID id) {
            return types[id];
        }
    };


}

#endif //BYSONVM_COMMANDTYPES_HPP
