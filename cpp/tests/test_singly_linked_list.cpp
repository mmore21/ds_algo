#include "catch.hpp"
#include "../lib/singly_linked_list.hpp"

TEST_CASE("Linked list push front")
{
    SinglyLinkedList<int> linkedList;

    SECTION("Push to empty linked list")
    {
        linkedList.push_front(0);
        REQUIRE(linkedList.size() == 1);
    }
}

TEST_CASE("Linked list push back")
{
    SinglyLinkedList<int> linkedList;

    SECTION("Push to empty linked list")
    {
        linkedList.push_back(0);
        REQUIRE(linkedList.size() == 1);
    }
}

TEST_CASE("Linked list pop front")
{
    SinglyLinkedList<int> linkedList;

    SECTION("Pop from empty linked list")
    {
        linkedList.pop_front();
        REQUIRE(linkedList.empty());
    }

    SECTION("Pop from list of size 1")
    {

        linkedList.push_back(0);
        linkedList.pop_front();
        REQUIRE(linkedList.empty());
    }

    SECTION("Pop from list of size greater than 1")
    {
        for (int i = 0; i < 5; i++)
        {
            linkedList.push_back(i);
        }
        linkedList.pop_front();
        REQUIRE(linkedList.size() == 4);
    }
}

TEST_CASE("Linked list pop back")
{
    SinglyLinkedList<int> linkedList;

    SECTION("Pop from empty linked list")
    {
        linkedList.pop_back();
        REQUIRE(linkedList.empty());
    }

    SECTION("Pop from list of size 1")
    {
        linkedList.push_back(0);
        linkedList.pop_back();
        REQUIRE(linkedList.empty());
    }

    SECTION("Pop from list of size greater than 1")
    {
        for (int i = 0; i < 5; i++)
        {
            linkedList.push_back(i);
        }
        linkedList.pop_back();
        REQUIRE(linkedList.size() == 4);
    }
}

TEST_CASE("Linked list empty")
{
    SinglyLinkedList<int> linkedList;
    
    SECTION("Empty linked list")
    {
        REQUIRE(linkedList.empty());
    }

    SECTION("Non-empty linked list")
    {
        linkedList.push_back(0);
        REQUIRE(!linkedList.empty());
    }
}

TEST_CASE( "Size of linked list" )
{
    SinglyLinkedList<int> linkedList;

    SECTION("Empty linked list")
    {
        REQUIRE(linkedList.empty());
    }

    SECTION("Non-empty linked list")
    {
        for (int i = 0; i < 5; i++)
        {
            linkedList.push_back(i);
        }
        REQUIRE(linkedList.size() == 5);
    }
}