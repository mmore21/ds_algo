#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "singly_linked_list.h"

TEST_CASE( "Size of linked list" )
{
    SinglyLinkedList<int> linkedList;

    SECTION("Empty linked list")
        REQUIRE(linkedList.size() == 0);

    SECTION("Non-empty linked list")
        for (int i = 0; i < 5; i++)
        {
            linkedList.push_back(i);
        }
        REQUIRE(linkedList.size() == 5);
}