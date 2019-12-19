#include "catch.hpp"
#include "../lib/stack.hpp"

TEST_CASE("Stack empty")
{
    Stack<int> stack;

    SECTION("Check empty on empty stack")
    {
        REQUIRE(stack.empty());
    }
    SECTION("Check empty on non-empty stack")
    {
        stack.push(0);
        REQUIRE(!stack.empty());
    }
}