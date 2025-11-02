"""
2. Write a program to implement Binary Tree using linked list
   along with all specified functions.
"""

class Node:
    """
    Define the structure for a tree node
    """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

"""
a) To create a binary tree.
(This will be a manual, hard-coded creation in the main block)
"""

def displayInorder(node):
    """
    b) To display tree using inorder (Left-Visit-Right)
    """
    if node is None:
        return
    displayInorder(node.left)   # 1. Visit left
    print(node.data, end=" ")   # 2. Visit root
    displayInorder(node.right)  # 3. Visit right

def displayPreorder(node):
    """
    c) To display tree using preorder (Visit-Left-Right)
    """
    if node is None:
        return
    print(node.data, end=" ")   # 1. Visit root
    displayPreorder(node.left)  # 2. Visit left
    displayPreorder(node.right) # 3. Visit right

def displayPostorder(node):
    """
    d) To display tree using postorder (Left-Right-Visit)
    """
    if node is None:
        return
    displayPostorder(node.left)  # 1. Visit left
    displayPostorder(node.right) # 2. Visit right
    print(node.data, end=" ")    # 3. Visit root

def countNodes(node):
    """
    e) To count number of node present in the tree.
    """
    if node is None:
        return 0
    # 1 (for current node) + count(left) + count(right)
    return 1 + countNodes(node.left) + countNodes(node.right)

def findHeight(node):
    """
    f) To find the height of the tree.
    (Height = number of edges in longest path from root to a leaf)
    """
    if node is None:
        return -1 # Height of an empty tree is -1
    
    leftHeight = findHeight(node.left)
    rightHeight = findHeight(node.right)
    
    # Return max of left/right height + 1 for the current node
    return max(leftHeight, rightHeight) + 1

def countLeafNodes(node):
    """
    g) To find the number of leaf node.
    (A leaf node has no children)
    """
    if node is None:
        return 0
    # If it has no children, it's a leaf
    if node.left is None and node.right is None:
        return 1
    # Otherwise, sum leaf nodes from left and right subtrees
    return countLeafNodes(node.left) + countLeafNodes(node.right)

def countInternalNodes(node):
    """
    h) To find the number of internal node.
    (An internal node has at least one child)
    """
    if node is None:
        return 0
    # If it has at least one child, it's an internal node
    if node.left is not None or node.right is not None:
        # 1 (for this node) + count from children
        return 1 + countInternalNodes(node.left) + countInternalNodes(node.right)
    
    return 0 # It's a leaf node

def searchTree(node, key):
    """
    i) To search a data present in the tree.
    (Returns True if found, False if not)
    """
    if node is None:
        return False # Key not found
    
    if node.data == key:
        return True # Key found
    
    # Search in left OR right subtree
    return searchTree(node.left, key) or searchTree(node.right, key)

# Main function to demonstrate
if __name__ == "__main__":
    
    # a) Create tree (manual construction)
    root = Node(10)
    root.left = Node(20)
    root.right = Node(30)
    root.left.left = Node(40)
    root.left.right = Node(50)
    root.right.left = Node(60)

    """
    The tree looks like:
      10
     /  \
    20    30
   / \    /
  40 50  60
    """
     
    print("\n--- Traversals ---")
    
    # b) Inorder
    print("Inorder (LVR):   ", end="")
    displayInorder(root) # 40 20 50 10 60 30
    print()
    
    # c) Preorder
    print("Preorder (VLR):  ", end="")
    displayPreorder(root) # 10 20 40 50 30 60
    print()
    
    # d) Postorder
    print("Postorder (LRV): ", end="")
    displayPostorder(root) # 40 50 20 60 30 10
    print()
    
    print("\n--- Statistics ---")

    # e) Count Nodes
    print(f"Total Nodes: {countNodes(root)}")
    
    # f) Find Height
    print(f"Height of Tree: {findHeight(root)}")
    
    # g) Count Leaf Nodes
    print(f"Leaf Nodes: {countLeafNodes(root)}")
    
    # h) Count Internal Nodes
    print(f"Internal Nodes: {countInternalNodes(root)}")
    
    print("\n--- Search ---")
    
    # i) Search
    key = 50
    if searchTree(root, key):
        print(f"Element {key} found.")
    else:
        print(f"Element {key} not found.")
    
    key = 99
    if searchTree(root, key):
        print(f"Element {key} found.")
    else:
        print(f"Element {key} not found.")

    # No need to manually free memory in Python
