#include "catch.hpp"
#include "../lib/binary_search_tree.hpp"

TEST_CASE("BST empty")
{
    BinarySearchTree<int> bst;

    SECTION("Check empty on empty BST")
    {
        REQUIRE(bst.empty());
    }
    SECTION("Check empty on non-empty BST")
    {
        bst.insert(0, 0);
        REQUIRE(!bst.empty());
    }
}

TEST_CASE("BST search")
{
    BinarySearchTree<int> bst;

    SECTION("Search empty BST")
    {
        REQUIRE(bst.search(0) == nullptr);
    }
    SECTION("Search non-existent key in non-empty BST")
    {
        bst.insert(0, 0);
        REQUIRE(bst.search(1) == nullptr);
    }
    SECTION("Search existing key in non-empty BST")
    {
        bst.insert(0, 0);
        REQUIRE(bst.search(0) != nullptr);
    }
}

TEST_CASE("BST insert")
{
    BinarySearchTree<int> bst;

    SECTION("Insert to empty BST")
    {
        bst.insert(0, 0);
        REQUIRE(bst.size() == 1);
    }
    SECTION("Insert to non-empty BST")
    {
        bst.insert(0, 0);
        bst.insert(1, 1);
        REQUIRE(bst.size() == 2);
    }
    SECTION("Insert and replace root of BST")
    {
        bst.insert(0, 0);
        bst.insert(0, 1);
        REQUIRE(bst.search(0)->value == 1);
    }
    SECTION("Insert and replace node of BST")
    {
        bst.insert(0, 0);
        bst.insert(1, 1);
        bst.insert(1, 2);
        REQUIRE(bst.search(1)->value == 2);
    }
}

TEST_CASE("BST remove")
{
    BinarySearchTree<int> bst;

    SECTION("Remove from empty BST")
    {
        REQUIRE_THROWS(bst.remove(0), std::exception());
    }
    SECTION("Remove root from BST with no children")
    {
        bst.insert(0, 0);
        bst.remove(0);
        REQUIRE(bst.size() == 0);
    }
    SECTION("Remove root from BST with only left child")
    {
        bst.insert(1, 1);
        bst.insert(0, 0);
        bst.remove(1);
        REQUIRE(bst.size() == 1);
    }
    SECTION("Remove root from BST with only right child")
    {
        bst.insert(0, 0);
        bst.insert(1, 1);
        bst.remove(0);
        REQUIRE(bst.size() == 1);
    }
    SECTION("Remoove root from BST with both children")
    {
        bst.insert(1, 1);
        bst.insert(0, 0);
        bst.insert(2, 2);
        bst.remove(1);
        REQUIRE(bst.size() == 2);
    }  
    SECTION("Remove from left subtree of BST")
    {
        bst.insert(2, 2);
        bst.insert(1, 1);
        bst.remove(1);
        REQUIRE(bst.size() == 1);
    }
    SECTION("Remove from right subtree of BST")
    {
        bst.insert(1, 1);
        bst.insert(2, 2);
        bst.remove(2);
        REQUIRE(bst.size() == 1);
    }
}