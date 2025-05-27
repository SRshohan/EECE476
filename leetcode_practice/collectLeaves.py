class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def collectLeaves(self, root):
        if not root:
            return []

        if not root.left and not root.right:
            return root.val
        # Recursively collect leaves from left and right subtrees
        left_leaves = self.collectLeaves(root.left)
        right_leaves = self.collectLeaves(root.right)

        return left_leaves + right_leaves


            
# Example usage:
# Constructing a sample tree
#       1
#      / \
#     2   3
#    / \
#   4   5
# The leaves are 4, 5, and 3

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    solution = Solution()
    leaves = solution.collectLeaves(root)
    print(leaves)  # Output: [4, 5, 3]
            
        


        
