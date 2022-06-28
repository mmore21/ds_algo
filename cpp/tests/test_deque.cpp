#include "catch.hpp"
#include "../src/deque.hpp"

TEST_CASE("Deque empty")
{
    Deque<int> deque;

    SECTION("Check empty on empty deque")
    {
        REQUIRE(deque.empty());
    }
    SECTION("Check empty on non-empty deque")
    {
        deque.push_back(0);
        REQUIRE(!deque.empty());
    }
}

TEST_CASE("Deque size")
{
    Deque<int> deque;

    SECTION("Size of empty deque")
    {
        REQUIRE(deque.size() == 0);
    }

    SECTION("Size of non-empty deque")
    {
        deque.push_back(0);
        REQUIRE(deque.size() == 1);
    }
}

TEST_CASE("Deque front")
{
    Deque<int> deque;

    SECTION("Front of empty deque")
    {
        REQUIRE_THROWS(deque.front(), std::exception());
    }

    SECTION("Front of non-empty deque")
    {
        deque.push_back(0);
        deque.push_back(1);
        deque.push_back(2);
        REQUIRE(deque.front() == 0);
    }
}

TEST_CASE("Deque back")
{
    Deque<int> deque;

    SECTION("Back of empty deque")
    {
        REQUIRE_THROWS(deque.back(), std::exception());
    }

    SECTION("Back of non-empty deque")
    {
        deque.push_back(0);
        deque.push_back(1);
        deque.push_back(2);
        REQUIRE(deque.back() == 2);
    }
}

TEST_CASE("Deque at")
{
    Deque<int> deque;

    SECTION("At of empty deque")
    {
        REQUIRE_THROWS(deque.at(0), std::exception());
    }

    SECTION("At of non-empty deque")
    {
        deque.push_back(0);
        deque.push_back(1);
        deque.push_back(2);
        REQUIRE(deque.at(0) == 0);
        REQUIRE(deque.at(1) == 1);
        REQUIRE(deque.at(2) == 2);
        REQUIRE_THROWS(deque.at(3), std::exception());
    }
}

TEST_CASE("Deque push back")
{
    Deque<int> deque;
    
    SECTION("Push back to empty deque")
    {
        deque.push_back(0);
        REQUIRE(deque.size() == 1);
    }
    SECTION("Push back to non-empty deque")
    {
        deque.push_back(0);
        deque.push_back(0);
        REQUIRE(deque.size() == 2);
    }
}

TEST_CASE("Deque push front")
{
    Deque<int> deque;
    
    SECTION("Push front to empty deque")
    {
        deque.push_front(0);
        REQUIRE(deque.size() == 1);
    }
    SECTION("Push front to non-empty deque")
    {
        deque.push_front(0);
        deque.push_front(0);
        REQUIRE(deque.size() == 2);
    }
}

TEST_CASE("Deque pop back")
{
    Deque<int> deque;

    SECTION("Pop back from empty deque")
    {
        REQUIRE_THROWS(deque.pop_back(), std::exception());
    }
    SECTION("Pop back from non-empty deque")
    {
        deque.push_back(0);
        deque.pop_back();
        REQUIRE(deque.size() == 0);
    }
}

TEST_CASE("Deque pop front")
{
    Deque<int> deque;

    SECTION("Pop front from empty deque")
    {
        REQUIRE_THROWS(deque.pop_front(), std::exception());
    }
    SECTION("Pop front from non-empty deque")
    {
        deque.push_back(0);
        deque.pop_front();
        REQUIRE(deque.size() == 0);
    }
}