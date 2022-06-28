#include "catch.hpp"
#include "../src/bubble_sort.hpp"

TEST_CASE("Bubble sort")
{
    std::vector<int> arr;

    SECTION("Already sorted")
    {
        arr = {1, 2, 3, 4, 5};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Already reverse sorted")
    {
        arr = {5, 4, 3, 2, 1};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Not sorted")
    {
        arr = {4, 2, 1, 5, 3};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }
}