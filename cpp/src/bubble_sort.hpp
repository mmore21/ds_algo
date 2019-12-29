#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>
#include <algorithm>

template <typename T>
void bubble_sort(std::vector<T> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr.at(j) < arr.at(j+1))
            {
                std::iter_swap(arr.begin() + j, arr.begin() + j + 1);
            }
        }
    }
}

#endif /* BUBBLE_SORT_HPP */