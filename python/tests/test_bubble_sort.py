import unittest
from lib.bubble_sort import bubble_sort

class BubbleSortTest(unittest.TestCase):
    def setUp(self):
        self.arr = []
    
    def test_bubble_sort(self):
        # Already sorted
        self.arr = [1, 2, 3, 4, 5]
        self.assertEqual(bubble_sort(self.arr), [1, 2, 3, 4, 5])
        # Already reverse sorted
        self.arr = [5, 4, 3, 2, 1]
        self.assertEqual(bubble_sort(self.arr), [1, 2, 3, 4, 5])
        # Not sorted
        self.arr = [4, 2, 1, 5, 3]
        self.assertEqual(bubble_sort(self.arr), [1, 2, 3, 4, 5])