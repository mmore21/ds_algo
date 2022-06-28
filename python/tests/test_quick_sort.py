import unittest
from lib.quick_sort import quick_sort

class QuickSortTest(unittest.TestCase):
    def setUp(self):
        self.arr = []
    
    def test_quick_sort(self):
        # Already sorted
        self.arr = [1, 2, 3, 4, 5]
        self.assertEqual(quick_sort(self.arr), [1, 2, 3, 4, 5])
        # Already reverse sorted
        self.arr = [5, 4, 3, 2, 1]
        self.assertEqual(quick_sort(self.arr), [1, 2, 3, 4, 5])
        # Not sorted
        self.arr = [4, 2, 1, 5, 3]
        self.assertEqual(quick_sort(self.arr), [1, 2, 3, 4, 5])