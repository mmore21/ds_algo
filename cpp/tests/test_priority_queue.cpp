#include "catch.hpp"
#include "../src/priority_queue.hpp"

TEST_CASE("Priority queue empty")
{
    PriorityQueue<int> pq;
    
    SECTION("Check empty on empty priority queue")
    {
        REQUIRE(pq.empty());
    }
    SECTION("Check empty on non-empty priority queue")
    {
        pq.push(0);
        REQUIRE(!pq.empty());
    }
}

TEST_CASE("Priority queue size")
{
    PriorityQueue<int> pq;

    SECTION("Size of empty priority queue")
    {
        REQUIRE(pq.size() == 0);
    }
    SECTION("Size of non-empty priority queue")
    {
        pq.push(0);
        REQUIRE(pq.size() == 1);
    }
}

TEST_CASE("Priority queue top")
{
    PriorityQueue<int> pq;

    SECTION("Top of empty priority queue")
    {
        REQUIRE_THROWS(pq.top(), std::exception());
    }
    SECTION("Top of non-empty priority queue")
    {
        pq.push(0);
        REQUIRE(pq.top() == 0);
    }
}

TEST_CASE("Priority queue push")
{
    PriorityQueue<int> pq;

    SECTION("Push to empty priority queue")
    {
        pq.push(0);
        REQUIRE(pq.size() == 1);
    }
    SECTION("Push to non-empty priority queue")
    {
        pq.push(0);
        pq.push(1);
        REQUIRE(pq.size() == 2);
    }
}

TEST_CASE("Priority queue pop")
{
    PriorityQueue<int> pq;

    SECTION("Pop from empty priority queue")
    {
        REQUIRE_THROWS(pq.pop(), std::exception());
    }
    SECTION("Pop from non-empty priority queue")
    {
        pq.push(0);
        pq.pop();
        REQUIRE(pq.size() == 0);
    }
}