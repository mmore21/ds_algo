class Node:
    def __init__(self, val):
        """ Constructor of Node class. """
        self.val = val
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        """ Constructor of BinarySearchTree class. """
        self.root = None

    def insert(self, node):
        """ Inserts a node into the BST. """
        # Set root node if uninitialized.
        if not self.root:
            self.root = node
        else:
            ptr = self.root
            # Iterate down branches until reaching location to insert new leaf node.
            while((ptr.left and node.val < ptr.val) or (ptr.right and node.val > ptr.val)):
                if (node.val < ptr.val):
                    ptr = ptr.left
                else:
                    ptr = ptr.right
            # Insert new leaf node.
            if (node.val < ptr.val):
                ptr.left = node
            elif (node.val > ptr.val):
                ptr.right = node

    # TODO: Finish deletion implementation.
    def delete(self, node, val):
        """ Deletes a node from BST and restructures if necessary. """
        if not self.root:
            print("37")
            return None
        
        if (val < node.val):
            self.delete(node.left, val)
            print("42")
        elif (val > node.val):
            self.delete(node.right, val)
            print("45")
        else:
            if (node.left == None and node.right == None):
                node = None
            elif (node.left == None):
                tmp = node
                node = node.right
            elif (node.right == None):
                tmp = node
                node = node.left
            else:
                tmp = self.find_min(node.left)
                node.val = tmp.val
                node.right = self.delete(node.right, tmp.val)

        return node

    def find_min(self, node):
        if (node == None):
            return None
        if (node.left != None):
            return self.find_min(node.left)
        return node.val

    def dfs(self, node):
        """ Performs an in-order DFS of BST. """
        if not node:
            return None
        
        if (node.left):
            self.dfs(node.left)

        print(node.val, end=' -> ')

        if (node.right):
            self.dfs(node.right)

def main():
    bst = BinarySearchTree()
    bst.insert(Node(5))
    bst.insert(Node(3))
    bst.insert(Node(1))
    bst.insert(Node(2))
    bst.insert(Node(5))
    bst.insert(Node(7))
    bst.insert(Node(8))
    bst.insert(Node(6))
    bst.dfs(bst.root)
    bst.delete(bst.root, 6)
    bst.dfs(bst.root)

if __name__ == "__main__":
    main()