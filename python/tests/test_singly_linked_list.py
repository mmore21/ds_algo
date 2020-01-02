import unittest
from lib.singly_linked_list import Node, SinglyLinkedList

class SinglyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.linkedList = SinglyLinkedList()

    def test_length(self):
        self.assertEqual(self.linkedList.length(), 0)
        self.linkedList.add(Node(1))
        self.assertEqual(self.linkedList.length(), 1)
    
    def test_find(self):
        self.assertEqual(self.linkedList.find(1), None)
        self.linkedList.add(Node(1))
        self.assertNotEqual(self.linkedList.find(1), None)

    def test_add(self):
        self.assertEqual(self.linkedList.length(), 0)
        self.linkedList.add(Node(1))
        self.assertEqual(self.linkedList.length(), 1)

    def test_delete(self):
        self.linkedList.add(Node(1))
        self.linkedList.add(Node(2))
        self.linkedList.delete(1)
        self.assertEqual(self.linkedList.length(), 1)
        self.linkedList.delete(0)
        self.assertEqual(self.linkedList.length(), 0)

if __name__=="__main__":
    unittest.main()