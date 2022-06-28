import unittest
from lib.insertion_sort import insertion_sort

class InsertionSortTest(unittest.TestCase):
    def setUp(self):
        self.arr = []
    
    def test_insertion_sort(self):
        # Already sorted
        self.arr = [1, 2, 3, 4, 5]
        self.assertEqual(insertion_sort(self.arr), [1, 2, 3, 4, 5])
        # Already reverse sorted
        self.arr = [5, 4, 3, 2, 1]
        self.assertEqual(insertion_sort(self.arr), [1, 2, 3, 4, 5])
        # Not sorted
        self.arr = [4, 2, 1, 5, 3]
        self.assertEqual(insertion_sort(self.arr), [1, 2, 3, 4, 5])