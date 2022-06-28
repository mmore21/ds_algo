import unittest
from lib.queue import Queue

class QueueTest(unittest.TestCase):
    def setUp(self):
        self.queue = Queue()

    def test_size(self):
        self.assertEqual(self.queue.size(), 0)
        self.queue.enqueue(1)
        self.assertEqual(self.queue.size(), 1)
    
    def test_peek(self):
        self.assertEqual(self.queue.peek(), None)
        self.queue.enqueue(1)
        self.assertEqual(self.queue.peek(), 1)
    
    def test_dequeue(self):
        self.queue.enqueue(1)
        self.queue.dequeue()
        self.assertEqual(self.queue.size(), 0)

    def test_enqueue(self):
        self.queue.enqueue(1)
        self.assertEqual(self.queue.size(), 1)
        
if __name__=="__main__":
    unittest.main()