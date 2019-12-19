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

TEST_CASE("Stack size")
{
    Stack<int> stack;

    SECTION("Size of empty stack")
    {
        REQUIRE(stack.size() == 0);
    }

    SECTION("Size of non-empty stack")
    {
        stack.push(0);
        REQUIRE(stack.size() == 1);
    }
}

TEST_CASE("Stack top")
{
    Stack<int> stack;

    SECTION("Top of empty stack")
    {
        REQUIRE_THROWS(stack.top(), std::exception());
    }

    SECTION("Top of non-empty stack")
    {
        stack.push(0);
        REQUIRE(stack.top() == 0);
    }
}

TEST_CASE("Stack push")
{
    Stack<int> stack;
    
    SECTION("Push to empty stack")
    {
        stack.push(0);
        REQUIRE(stack.size() == 1);
    }
    SECTION("Push to non-empty stack")
    {
        stack.push(0);
        stack.push(0);
        REQUIRE(stack.size() == 2);
    }
}

TEST_CASE("Stack pop")
{
    Stack<int> stack;

    SECTION("Pop from empty stack")
    {
        REQUIRE_THROWS(stack.pop(), std::exception());
    }
    SECTION("Pop from non-empty stack")
    {
        stack.push(0);
        stack.pop();
        REQUIRE(stack.size() == 0);
    }
}