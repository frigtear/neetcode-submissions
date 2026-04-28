# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        max_diameter = 0

        def helper(node):
            nonlocal max_diameter
            if node:
                
                left = helper(node.left)
                right = helper(node.right)
                max_diameter = max(max_diameter, left + right)
                return 1 + max(left, right)
            else:
                return 0

        helper(root)
        return max_diameter
            
                