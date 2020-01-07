import unittest
from lib.graph import Graph

class GraphTest(unittest.TestCase):
    def setUp(self):
        self.graph = Graph()

    def test_add(self):
        self.graph.add(0, 1)
        self.assertEqual(self.graph.at(0), {1})
        self.graph.add(0, 2)
        self.assertEqual(self.graph.at(0), {1, 2})
        self.graph.add(0, 2)
        self.assertEqual(self.graph.at(0), {1, 2})
    
    def test_at(self):
        self.assertEqual(self.graph.at(0), {})
        self.graph.add(0, 1)
        self.assertEqual(self.graph.at(0), {1})

if __name__=="__main__":
    unittest.main()