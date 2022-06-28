#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>
#include <algorithm>

template <typename T>
void insertion_sort(std::vector<T> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j > 0 && arr.at(j) < arr.at(j - 1); j--)
        {
            std::iter_swap(arr.begin() + j, arr.begin() + j - 1);
        }
    }
}

#endif /* INSERTION_SORT_HPP */
