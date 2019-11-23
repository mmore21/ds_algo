"""
Topic: Queue
Category: Data Structure
Author: Mason Moreland
"""

class Queue:
    def __init__(self):
        """ Constructor of Queue class. """
        self.queue = []

    def enqueue(self, val):
        """ Add item to end of queue. """
        self.queue.append(val)

    def dequeue(self):
        """ Remove item from front of queue. """
        self.queue.pop(0)

    def peek(self):
        """ Gets item at front of queue. """
        if self.size() > 0:
            return self.queue[0]
        else:
            return None

    def size(self):
        """ Gets size of queue. """
        return len(self.queue)

    def __str__(self):
        """ Override default string format of queue when printed. """
        return f"Queue object: {self.queue}"

        
def main():
    """ Driver function for an example queue. """
    print("Enqueuing")
    q = Queue()
    q.enqueue(5)
    q.enqueue(6)
    q.enqueue(7)
    print(q)
    print("Peek:", q.peek())
    print("\nDequeuing...")
    q.dequeue()
    print(q)
    print("Size:", q.size())
    print("\nDequeuing...")
    q.dequeue()
    q.dequeue()
    print(q)
    print("Peek:", q.peek())
    print("Size:", q.size())

if __name__ == "__main__":
    main()