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
        if self.root.val == val:
            if (not self.root.left and not self.root.right):
                self.root = None
            elif (not self.root.left):
                self.root = self.root.right
            elif (not self.root.right):
                self.root = self.root.left
            else:
                min_node, parent_node = self.find_min(self.root.right)
                print("VALS:", min_node.val, parent_node.val)
                self.root.val = min_node.val
                parent_node.left = None
            return True
        
        if not node:
            return False
        
        if (val < node.val and node.left):
            if (val == node.left.val):
                child = node.left
                if (not child.left and not child.right):
                    node.left = None
                elif (not child.left):
                    node.left = child.right
                elif (not child.right):
                    node.left = child.left
                else:
                    min_node, parent_node = self.find_min(child)
                    node.left.val = min_node.val
                    parent_node.left = None
                return True
            else:
                self.delete(node.left, val)
        elif (val > node.val and node.right):
            if (val == node.right.val):
                child = node.right
                if (not child.left and not child.right):
                    node.right = None
                elif (not child.left):
                    node.right = child.right
                elif (not child.right):
                    node.right = child.left
                else:
                    min_node, parent_node = self.find_min(child)
                    node.right.val = min_node.val
                    parent_node.left = None
                return True
            else:
                self.delete(node.right, val)
        else:
            return False
        

    def find_min(self, node):
        parent = node
        if (node == None):
            return None
        while (node.left != None):
            parent = node
            node = node.left
        return [node, parent]

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
    bst.insert(Node(2))
    bst.insert(Node(1))
    bst.insert(Node(3))
    bst.insert(Node(5))
    bst.insert(Node(7))
    bst.insert(Node(8))
    bst.insert(Node(6))
    bst.dfs(bst.root)
    print("")
    bst.delete(bst.root, 6)
    bst.delete(bst.root, 2)
    bst.delete(bst.root, 1)
    bst.delete(bst.root, 7)
    bst.delete(bst.root, 5)
    print("HERE:" )
    bst.delete(bst.root, 3)
    bst.delete(bst.root, 8)
    bst.dfs(bst.root)
    print("")
    bst.dfs(bst.root)

if __name__ == "__main__":
    main()