"""
Topic: Merge Sort
Category: Algorithm
Author: Mason Moreland
Runtime: O(nlog(n))
"""

def merge(arr1, arr2):
    merged_arr = []
    while (len(arr1) and len(arr2)):
        if (arr1[0] > arr2[0]):
            merged_arr.append(arr2[0])
            arr2.pop(0)
        else:
            merged_arr.append(arr1[0])
            arr1.pop(0)
    
    while(len(arr1)):
        merged_arr.append(arr1[0])
        arr1.pop(0)
    
    while (len(arr2)):
        merged_arr.append(arr2[0])
        arr2.pop(0)
    
    return merged_arr

def merge_sort(arr):
    if (len(arr) == 1):
        return arr
    
    partition1 = arr[:len(arr)//2]
    partition2 = arr[len(arr)//2:]

    partition1 = merge_sort(partition1)
    partition2 = merge_sort(partition2)

    return merge(partition1, partition2)