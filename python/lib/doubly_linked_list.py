"""
Topic: Doubly Linked List
Category: Data Structure
Author: Mason Moreland
"""

class Node:
    def __init__(self, val, next=None, prev=None):
        """ Constructor of Node class. """
        self.val = val
        self.next = next
        self.prev = prev

    def __str__(self):
        """ Override default string format of node when printed. """
        return f"Node object: val={self.val}"

class DoublyLinkedList:
    def __init__(self):
        """ Constructor of DoublyLinkedList class. """
        self.head = None
        self.tail = None
    
    def addFront(self, node):
        """ Add a node to the head of the doubly linked list. """
        if (self.head == None):
            self.head = node
            self.tail = node
        else:
            ptr = self.head
            ptr.prev = node
            node.next = ptr
            self.head = ptr.prev
    
    def addEnd(self, node):
        """ Add a node to the tail of the doubly linked list. """
        if (self.head == None):
            self.head = node
            self.tail = node
        else:
            ptr = self.tail
            ptr.next = node
            node.prev = ptr
            self.tail = ptr.next

    def insert(self, node, index):
        """ Insert a node at a specified index of the doubly linked list. """
        if (index < 0 or index > self.length()):
            raise IndexError("Insertion index outside of doubly linked list boundaries.")
        elif (index == 0):
            # adds to front and replaces head
            self.addFront(node)
        elif (index == self.length()):
            # adds to end and replaces tail
            self.addEnd(node)
        else:
            ptr = self.head
            for _ in range(index):
                ptr = ptr.next
            node.next = ptr
            node.prev = ptr.prev
            ptr.prev.next = node
            ptr.prev = node
    
    def delete(self, index):
        """ Delete a node from the doubly linked list at a specified index. """
        # Raise IndexError if deletion index is out of doubly linked list range.
        if (index < 0 or index > self.length() - 1):
            raise IndexError("Deletion index outside of doubly linked list boundaries.")

        # Initialize variable to be set to value of deleted node
        val = None

        # Special deletion case if index is 0 (head)
        if (index == 0):
            val = self.head.val
            self.head = self.head.next
        else:
            pos = 0
            ptr = self.head

            # Iterate over doubly linked list until at node before deletion index
            while (pos != index - 1):
                ptr = ptr.next
                pos += 1
            # Set variable to value of node that will be deleted
            val = ptr.next.val
            # Change the link of the previous node to the deleted node's next link
            ptr.next = ptr.next.next
        
        return val

    def find(self, val):
        """ Iteratively search for value in the doubly linked list. """
        ptr = self.head
        while (ptr != None):
            if ptr.val == val:
                return ptr
            ptr = ptr.next
        return None

    def length(self):
        """ Get the length of the doubly linked list. """
        n = 0
        ptr = self.head
        while (ptr != None):
            n += 1
            ptr = ptr.next
        return n
    
    def __str__(self):
        """ Override default string format of doubly linked list when printed. """
        s = ""
        ptr = self.head
        while (ptr != None):
            s += f"{ptr.val} -> "
            ptr = ptr.next
        return s
        
def main():
    """ Driver function for an example doubly linked list. """
    print("Adding:")
    list = DoublyLinkedList()
    list.addEnd(Node(3))
    print(list)
    list.addFront(Node(5))
    print(list)
    list.addFront(Node(6))
    list.insert(Node(9), 1)
    print(list)
    print("Length:", list.length())
    print("\nSearching:")
    print(list.find(5))
    print("\nDeleting:")
    list.delete(1)
    print(list)
    list.delete(1)
    print(list)
    list.delete(0)
    print(list)
    list.delete(0)
    print(list)
    print("Length:", list.length())
    print("\nInserting:")
    list.addEnd(Node(4))
    list.insert(Node(0), 0)
    list.insert(Node(3), 2)
    print(list)
    print("Length:", list.length())
    print("\nDeleting:")
    list.delete(2)
    print(list)
    list.delete(1)
    print(list)
    list.delete(0)
    print(list)
    print("Length:", list.length())

if __name__ == "__main__":
    main()