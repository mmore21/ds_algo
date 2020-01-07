"""
Topic: Graph
Category: Data Structure
Author: Mason Moreland
"""

class Graph:
    def __init__(self):
        """ Constructor of Graph class. """
        self.graph = {}
    
    def add(self, origin, destination):
        if (origin not in self.graph):
            self.graph[origin] = set([destination])
        else:
            self.graph[origin].add(destination)
    
    def at(self, origin):
        if (origin not in self.graph):
            return {}
        else:
            return self.graph[origin]

if __name__ == "__main__":
    g = Graph()
    g.add(3, 4)
    g.add(3, 5)
    g.add(3, 4)
    g.add(2, 4)
    print(g.at(5))