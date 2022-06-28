import unittest
from lib.deque import Deque

class DequeTest(unittest.TestCase):
    def setUp(self):
        self.deque = Deque()

    def test_size(self):
        self.assertEqual(self.deque.size(), 0)
        self.deque.push_back(1)
        self.assertEqual(self.deque.size(), 1)
    
    def test_front(self):
        self.assertEqual(self.deque.front(), None)
        self.deque.push_back(1)
        self.assertEqual(self.deque.front(), 1)

    def test_back(self):
        self.assertEqual(self.deque.back(), None)
        self.deque.push_back(1)
        self.assertEqual(self.deque.back(), 1)

    def test_push_front(self):
        self.deque.push_front(1)
        self.assertEqual(self.deque.size(), 1)
        
    def test_push_back(self):
        self.deque.push_back(1)
        self.assertEqual(self.deque.size(), 1)

    def test_pop_front(self):
        self.deque.push_back(1)
        self.deque.pop_front()
        self.assertEqual(self.deque.size(), 0)
    
    def test_pop_back(self):
        self.deque.push_back(1)
        self.deque.pop_back()
        self.assertEqual(self.deque.size(), 0)

if __name__=="__main__":
    unittest.main()