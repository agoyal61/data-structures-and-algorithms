
class Node:
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# This function returns the height of the binary tree
def height(node):
    if node is None:
        return 0
    return 1 + max(height(node.left), height(node.right))
        