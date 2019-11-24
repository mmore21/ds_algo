"""
Topic: Stack
Category: Data Structure
Author: Mason Moreland
"""

class Stack:
    def __init__(self):
        """ Constructor of Stack class. """
        self.stack = []

    def push(self, val):
        """ Add item to top of stack. """
        self.stack.append(val)

    def pop(self):
        """ Remove item from top of stack. """
        del self.stack[-1]

    def peek(self):
        """ Gets item at top of stack. """
        if self.size():
            return self.stack[self.size() - 1]
        else:
            return None

    def size(self):
        """ Gets size of stack. """
        return len(self.stack)

    def __str__(self):
        """ Override default string format of stack when printed. """
        return f"Stack object: {self.stack}"
        
def main():
    """ Driver function for an example queue. """
    print("Pushing...")
    s = Stack()
    s.push(5)
    s.push(6)
    s.push(7)
    print(s)
    print("Peek:", s.peek())
    print("\nPopping...")
    s.pop()
    print(s)
    print("Size:", s.size())
    print("\nPopping...")
    s.pop()
    s.pop()
    print(s)
    print("Peek:", s.peek())
    print("Size:", s.size())

if __name__ == "__main__":
    main()