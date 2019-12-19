#include "catch.hpp"
#include "../lib/queue.hpp"

TEST_CASE("Queue empty")
{
    Queue<int> queue;

    SECTION("Check empty on empty queue")
    {
        REQUIRE(queue.empty());
    }
    SECTION("Check empty on non-empty queue")
    {
        queue.push(0);
        REQUIRE(!queue.empty());
    }
}

TEST_CASE("Queue size")
{
    Queue<int> queue;

    SECTION("Size of empty queue")
    {
        REQUIRE(queue.size() == 0);
    }

    SECTION("Size of non-empty queue")
    {
        queue.push(0);
        REQUIRE(queue.size() == 1);
    }
}

TEST_CASE("Queue front")
{
    Queue<int> queue;

    SECTION("Front of empty queue")
    {
        REQUIRE_THROWS(queue.front(), std::exception());
    }

    SECTION("Front of non-empty queue")
    {
        queue.push(0);
        queue.push(1);
        queue.push(2);
        REQUIRE(queue.front() == 0);
    }
}

TEST_CASE("Queue back")
{
    Queue<int> queue;

    SECTION("Back of empty queue")
    {
        REQUIRE_THROWS(queue.back(), std::exception());
    }

    SECTION("Back of non-empty queue")
    {
        queue.push(0);
        queue.push(1);
        queue.push(2);
        REQUIRE(queue.back() == 2);
    }
}

TEST_CASE("Queue push")
{
    Queue<int> queue;
    
    SECTION("Push to empty queue")
    {
        queue.push(0);
        REQUIRE(queue.size() == 1);
    }
    SECTION("Push to non-empty queue")
    {
        queue.push(0);
        queue.push(0);
        REQUIRE(queue.size() == 2);
    }
}

TEST_CASE("Queue pop")
{
    Queue<int> queue;

    SECTION("Pop from empty queue")
    {
        REQUIRE_THROWS(queue.pop(), std::exception());
    }
    SECTION("Pop from non-empty queue")
    {
        queue.push(0);
        queue.pop();
        REQUIRE(queue.size() == 0);
    }
}