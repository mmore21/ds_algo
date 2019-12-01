import unittest
from lib.stack import *

class StackTest(unittest.TestCase):
    def setUp(self):
        self.stack = Stack()

    def test_size(self):
        self.assertEqual(self.stack.size(), 0)
        self.stack.push(1)
        self.assertEqual(self.stack.size(), 1)
    
    def test_peek(self):
        self.assertEqual(self.stack.peek(), None)
        self.stack.push(1)
        self.assertEqual(self.stack.peek(), 1)
    
    def test_pop(self):
        self.stack.push(1)
        self.stack.pop()
        self.assertEqual(self.stack.size(), 0)

    def test_push(self):
        self.stack.push(1)
        self.assertEqual(self.stack.size(), 1)
        
if __name__=="__main__":
    unittest.main()