# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        def heightOfSubtree(node):
            if node:
                return 1 + max(heightOfSubtree(node.right), heightOfSubtree(node.left))
            else:
                return 0

        if root:
            height_left = heightOfSubtree(root.left)
            height_right = heightOfSubtree(root.right)
            return abs(height_left-height_right) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)
        else:
            return 0
        