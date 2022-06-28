"""
Topic: Quick Sort
Category: Algorithm
Author: Mason Moreland
Runtime: O(nlog(n))
"""

def _partition_lomuto(arr, low, high):
    pivot = arr[high]
    i = low

    for j in range(low, high):
        if arr[j] < pivot:
            tmp = arr[i]
            arr[i] = arr[j]
            arr[j] = tmp
            i += 1

    tmp = arr[i]
    arr[i] = arr[high]
    arr[high] = tmp
    
    return i

def _quick_sort(arr, low, high):
    if low < high:
        partition_index = _partition_lomuto(arr, low, high)
        _quick_sort(arr, low, partition_index - 1)
        _quick_sort(arr, partition_index + 1, high)
    return arr

def quick_sort(arr):
    return _quick_sort(arr, 0, len(arr) - 1)