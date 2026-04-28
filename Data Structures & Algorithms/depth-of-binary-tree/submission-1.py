# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        def helper(node, depth):

            if not node or (node.left is None and node.right is None):
                return depth
            elif node.right and node.left:
                return max(helper(node.right, depth + 1), helper(node.left, depth + 1))
            elif node.right:
                return helper(node.right, depth + 1)
            return helper(node.left, depth + 1)

        if not root:
            return 0

        return helper(root, 1)
        
            

            