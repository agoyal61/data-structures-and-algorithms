from  binary_tree_height import height

# Time complexity: O(n^2)
# Space complexity: O(n)
# This function returns the diameter of the binary tree
def diameter(root):
    if root is None:
        return 0
    return max(diameter(root.left), diameter(root.right), height(root.left) + height(root.right) + 1)


class Height:
    def __init__(self):
        self.h = 0

# Time complexity: O(n)
# Space complexity: O(n)
def diameterOpt(root, height):
    lh = Height()
    rh = Height()

    if root is None:
        height.h = 0
        return 0

    ldiameter = diameterOpt(root.left, lh)
    rdiameter = diameterOpt(root.right, rh)

    height.h = max(lh.h, rh.h) + 1

    return max(lh.h + rh.h + 1, max(ldiameter, rdiameter))