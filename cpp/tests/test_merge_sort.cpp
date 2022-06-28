#include "catch.hpp"
#include "../src/merge_sort.hpp"

TEST_CASE("Merge sort")
{
    std::vector<int> arr;

    SECTION("Already sorted")
    {
        arr = {1, 2, 3, 4, 5};
        merge_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Already reverse sorted")
    {
        arr = {5, 4, 3, 2, 1};
        merge_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Not sorted")
    {
        arr = {4, 2, 1, 5, 3};
        merge_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }
}