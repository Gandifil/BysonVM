#include <parsing/StringCommandParser.hpp>
#include <parsing/CommandParserLogger.hpp>
#include <Machine.hpp>

using namespace Byson::VirtualMachine;

int main() {
    Machine machine{ new CommandParserLogger{new StringCommandParser{}}  };
    return machine.run();
}
