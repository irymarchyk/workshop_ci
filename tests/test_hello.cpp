#include "hello.hpp"

#include <sstream>

#include <gtest/gtest.h>

TEST(hello, first)
{
    std::stringstream out;
    hello::greetings(out);
    ASSERT_FALSE(out.str().empty());
}
