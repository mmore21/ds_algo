"""
Topic: Deque
Category: Data Structure
Author: Mason Moreland
"""

class Deque:
    def __init__(self):
        """ Constructor of Deque class. """
        self.deque = []

    def push_back(self, val):
        """ Add item to end of deque. """
        self.deque.append(val)

    def push_front(self, val):
        """ Add item to front of deque. """
        self.deque.insert(0, val)

    def pop_front(self):
        """ Add item to end of deque. """
        if self.size():
            self.deque.pop(0)
        else:
            raise IndexError("Deque is empty.")

    def pop_back(self):
        """ Remove item from end of deque. """
        if self.size():
            self.deque.pop(-1)
        else:
            raise IndexError("Deque is empty.")

    def front(self):
        """ Gets item at front of deque. """
        if self.size():
            return self.deque[0]
        else:
            return None
    
    def back(self):
        """ Gets item at back of deque. """
        if self.size():
            return self.deque[-1]
        else:
            return None

    def size(self):
        """ Gets size of deque. """
        return len(self.deque)

    def __str__(self):
        """ Override default string format of deque when printed. """
        return f"deque object: {self.deque}"

        
def main():
    """ Driver function for an example deque. """
    print("Pushing...")
    d = Deque()
    d.push_back(5)
    d.push_front(6)
    d.push_front(7)
    print(d)
    print("Front:", d.front())
    print("Back:", d.back())
    print("\nPopping...")
    d.pop_front()
    print(d)
    print("Size:", d.size())
    print("\nPopping...")
    d.pop_back()
    d.pop_back()
    print(d)
    print("Front:", d.front())
    print("Back:", d.back())
    print("Size:", d.size())

if __name__ == "__main__":
    main()