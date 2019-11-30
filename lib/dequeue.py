"""
Topic: Dequeue
Category: Data Structure
Author: Mason Moreland
"""

class Dequeue:
    def __init__(self):
        """ Constructor of Dequeue class. """
        self.dequeue = []

    def push_back(self, val):
        """ Add item to end of dequeue. """
        self.dequeue.append(val)

    def push_front(self, val):
        """ Add item to front of dequeue. """
        self.dequeue.insert(0, val)

    def pop_front(self):
        """ Add item to end of dequeue. """
        if self.size():
            self.dequeue.pop(0)
        else:
            raise IndexError("Dequeue is empty.")

    def pop_back(self):
        """ Remove item from end of dequeue. """
        if self.size():
            self.dequeue.pop(-1)
        else:
            raise IndexError("Dequeue is empty.")

    def front(self):
        """ Gets item at front of dequeue. """
        if self.size():
            return self.dequeue[0]
        else:
            return None
    
    def back(self):
        """ Gets item at back of dequeue. """
        if self.size():
            return self.dequeue[-1]
        else:
            return None

    def size(self):
        """ Gets size of dequeue. """
        return len(self.dequeue)

    def __str__(self):
        """ Override default string format of dequeue when printed. """
        return f"Dequeue object: {self.dequeue}"

        
def main():
    """ Driver function for an example dequeue. """
    print("Pushing...")
    d = Dequeue()
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