#include "catch.hpp"
#include "../src/insertion_sort.hpp"

TEST_CASE("Insertion sort")
{
    std::vector<int> arr;

    SECTION("Already sorted")
    {
        arr = {1, 2, 3, 4, 5};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }
    
    SECTION("Already reverse sorted")
    {
        arr = {5, 4, 3, 2, 1};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Not sorted")
    {
        arr = {4, 2, 1, 5, 3};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }
}
