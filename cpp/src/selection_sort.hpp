#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
#include <algorithm>
#include <limits>

template <typename T>
void selection_sort(std::vector<T> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;

        for (int j = i; j < arr.size(); j++)
        {
            if (arr.at(j) < arr.at(minIndex))
            {
                minIndex = j;
            }
        }
        std::iter_swap(arr.begin() + i, arr.begin() + minIndex);
    }
}

#endif /* SELECTION_SORT_HPP */
