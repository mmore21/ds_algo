#include "catch.hpp"
#include "../src/hash_table.hpp"

TEST_CASE("Instantiate a hash table")
{
    SECTION("Default HashTable constructor")
    {
        HashTable<int> hashTable;
    }
    SECTION("Overridden HashTable constructor")
    {
        HashTable<int> hashTable(10);
    }
}

TEST_CASE("Add a value to the hash table")
{
    HashTable<int> hashTable(20);

    SECTION("Hash table is empty")
    {
        hashTable.insert(10);
        REQUIRE(hashTable.search(10) == 10);
    }

    SECTION("Hash table is not empty and no collision")
    {
        hashTable.insert(10);
        hashTable.insert(20);
        REQUIRE(hashTable.search(10) == 10);
        REQUIRE(hashTable.search(20) == 20);
    }

    SECTION("Hash table is not empty and collision")
    {
        hashTable.insert(10);
        hashTable.insert(20);
        hashTable.insert(30);
        REQUIRE(hashTable.search(10) == 10);
        REQUIRE(hashTable.search(20) == 20);
        REQUIRE(hashTable.search(30) == 30);
    }
}