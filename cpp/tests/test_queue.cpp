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