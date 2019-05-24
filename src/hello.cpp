#include "hello.hpp"

std::ostream& hello::greetings(std::ostream &stream)
{
    stream << "hello" << std::endl;

    return stream;
}
