"""
Topic: Singly Linked List
Category: Data Structure
Author: Mason Moreland
"""

class Node:
    def __init__(self, val, next=None):
        """ Constructor of Node class. """
        self.val = val
        self.next = next

    def __str__(self):
        """ Override default string format of node when printed. """
        return f"Node object: val={self.val}"

class SinglyLinkedList:
    def __init__(self, head=None):
        """ Constructor of SinglyLinkedList class. """
        self.head = head
    
    def add(self, node):
        """ Append a node to the end of the linked list. """
        if (self.head == None):
            self.head = node
        else:
            ptr = self.head
            while (ptr.next != None):
                ptr = ptr.next
            ptr.next = node
    
    def delete(self, index):
        """ Delete a node from the linked list at a specified index. """
        # Raise IndexError if deletion index is out of linked list range.
        if (index < 0 or index > self.length() - 1):
            raise IndexError("Deletion index outside of linked list boundaries.")

        # Initialize variable to be set to value of deleted node
        val = None

        # Special deletion case if index is 0 (head)
        if (index == 0):
            val = self.head.val
            self.head = self.head.next
        else:
            pos = 0
            ptr = self.head

            # Iterate over linked list until at node before deletion index
            while (pos != index - 1):
                ptr = ptr.next
                pos += 1
            # Set variable to value of node that will be deleted
            val = ptr.next.val
            # Change the link of the previous node to the deleted node's next link
            ptr.next = ptr.next.next
        
        return val

    def find(self, val):
        """ Iteratively search for value in the linked list. """
        ptr = self.head
        while (ptr != None):
            if ptr.val == val:
                return ptr
            ptr = ptr.next
        return None

    def length(self):
        """ Get the length of the linked list. """
        n = 0
        ptr = self.head
        while (ptr != None):
            n += 1
            ptr = ptr.next
        return n
    
    def __str__(self):
        """ Override default string format of linked list when printed. """
        s = ""
        ptr = self.head
        while (ptr != None):
            s += f"{ptr.val} -> "
            ptr = ptr.next
        return s
        
def main():
    """ Driver function for an example singly linked list. """
    print("Adding:")
    list = SinglyLinkedList(Node(4))
    print(list)
    list.add(Node(5))
    print(list)
    list.add(Node(6))
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
    print("Length:", list.length())
    print("\nAdding:")
    list.add(Node(4))
    print(list)
    print("Length:", list.length())

if __name__ == "__main__":
    main()