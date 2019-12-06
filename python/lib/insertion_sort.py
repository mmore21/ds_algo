"""
Topic: Insertion Sort
Category: Algorithm
Author: Mason Moreland
Runtime: O(n^2)
"""

def insertion_sort(arr):
    """
    Choose any element in original list and insert in order in newly partitioned list.
    """
    # Iterate over list once
    for i in range(len(arr)):
        j = i
        # Iteratively check current and left element and swap if current is smaller
        while (j != 0 and arr[j] < arr[j-1]):
            tmp = arr[j-1]
            arr[j-1] = arr[j]
            arr[j] = tmp
            j-=1
            
    return arr

def main():
    """ Driver function of an example insertion sort. """
    print(insertion_sort([5,3,2,6,1,8]))

if __name__=="__main__":
    main()
