#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>
#include <algorithm>

template <typename T>
int partition_lomuto(std::vector<T> &arr, int low, int high)
{
    T pivot = arr.at(high);
    int i = low;

    for (int j = low, j < high; j++)
    {
        if (arr.at(j) < pivot)
        {
            std::iter_swap(arr.begin() + i, arr.begin() + j)
            i++;
        }
    }

    std::iter_swap(arr.begin() + i, arr.begin() + high);

    return i;
}

template <typename T>
void quick_sort_helper(std::vector<T> &arr, int low, int high)
{
    if (low < high)
    {
        int partition_index = partition_lomuto(arr, low, high);
        quick_sort_helper(arr, low, partition_index + 1);
        quick_sort_helper(arr, partition_index + 1, high);
    }
}

template <typename T>
void quick_sort(std::vector<T> &arr)
{
    quick_sort_helper(arr, 0, arr.size() - 1);
}

#endif /* QUICK_SORT_HPP */
