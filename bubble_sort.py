"""
Topic: Bubble Sort
Category: Algorithm
Author: Mason Moreland
Runtime: O(n^2)
"""

def bubble_sort(arr):
    """
    Passes over a list comparing two elements and repeats with a smaller,
    sliced off end of the list each iteration until sorted.
    """
    for i, n1 in enumerate(arr):
        for j in range(len(arr) - i - 1):
            # swap if left element is greater than right element
            if (arr[j] > arr[j+1]):
                tmp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = tmp
    return arr

def main():
    """ Driver function of an example bubble sort. """
    print(bubble_sort([5,3,2,6,1,8]))

if __name__=="__main__":
    main()
