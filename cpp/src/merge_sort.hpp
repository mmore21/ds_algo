#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <algorithm>

template <typename T>
std::vector<T> merge(std::vector<T> &arr1, std::vector<T> &arr2)
{
    std::vector<T> merged_arr;
    while(arr1.size() && arr2.size())
    {
        if (arr1.at(0) > arr2.at(0))
        {
            merged_arr.push_back(arr2.at(0));
            arr2.erase(arr2.begin());
        }
        else
        {
            merged_arr.push_back(arr1.at(0));
            arr1.erase(arr1.begin());
        }
    }

    while (arr1.size())
    {
        merged_arr.push_back(arr1.at(0));
        arr1.erase(arr1.begin());
    }

    while (arr2.size())
    {
        merged_arr.push_back(arr2.at(0));
        arr2.erase(arr2.begin());
    }

    return merged_arr;
}

template <typename T>
void merge_sort(std::vector<T> &arr)
{
    if (arr.size() == 1)
    {
        return;
    }

    std::vector<T> partition1 = std::vector<T>(arr.begin(), arr.begin() + (arr.size() / 2));
    std::vector<T> partition2 = std::vector<T>(arr.begin() + (arr.size() / 2), arr.end());

    merge_sort(partition1);
    merge_sort(partition2);

    const std::vector<T> &merged_arr = merge(partition1, partition2);
    arr.assign(merged_arr.begin(), merged_arr.end());
}

#endif /* MERGE_SORT_HPP */