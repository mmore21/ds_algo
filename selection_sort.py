"""
Topic: Selection Sort
Category: Algorithm
Author: Mason Moreland
Runtime: O(n^2)
"""

def selection_sort(arr):
    """
    Iterate over list to find minimum element then swap with left value of list.
    Slice off left value of list and continue repeating this iteration.
    """
    for i in range(len(arr)):
        minIndex = i
        for j in range(i, len(arr)):
            if arr[j] < arr[minIndex]:
                minIndex = j
        tmp = arr[minIndex]
        arr[minIndex] = arr[i]
        arr[i] = tmp
    return arr

def main():
    """ Driver function of an example selection sort. """
    print(selection_sort([5,3,2,6,1,8]))

if __name__=="__main__":
    main()
