import unittest
from lib.doubly_linked_list import Node, DoublyLinkedList

class DoublyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.linkedList = DoublyLinkedList()

    def test_length(self):
        self.assertEqual(self.linkedList.length(), 0)
        self.linkedList.addEnd(Node(1))
        self.assertEqual(self.linkedList.length(), 1)
    
    def test_find(self):
        self.assertEqual(self.linkedList.find(1), None)
        self.linkedList.addEnd(Node(1))
        self.assertNotEqual(self.linkedList.find(1), None)

    def test_addFront(self):
        self.assertEqual(self.linkedList.length(), 0)
        self.linkedList.addFront(Node(1))
        self.assertEqual(self.linkedList.length(), 1)

    def test_addEnd(self):
        self.assertEqual(self.linkedList.length(), 0)
        self.linkedList.addEnd(Node(1))
        self.assertEqual(self.linkedList.length(), 1)

    def test_insert(self):
        self.assertEqual(self.linkedList.length(), 0)
        self.linkedList.insert(Node(1), 0)
        self.assertEqual(self.linkedList.length(), 1)
        self.linkedList.insert(Node(2), 0)
        self.assertEqual(self.linkedList.length(), 2)

    def test_delete(self):
        self.linkedList.addEnd(Node(1))
        self.linkedList.addEnd(Node(2))
        self.linkedList.delete(1)
        self.assertEqual(self.linkedList.length(), 1)
        self.linkedList.delete(0)
        self.assertEqual(self.linkedList.length(), 0)

if __name__=="__main__":
    unittest.main()