#include "catch.hpp"
#include "../src/selection_sort.hpp"

TEST_CASE("Selection sort")
{
    std::vector<int> arr;

    SECTION("Already sorted")
    {
        arr = {1, 2, 3, 4, 5};
        selection_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Already reverse sorted")
    {
        arr = {5, 4, 3, 2, 1};
        selection_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Not sorted")
    {
        arr = {4, 2, 1, 5, 3};
        selection_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
    }
}
