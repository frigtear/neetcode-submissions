# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        def helper(node, other):
            if node is None and other is None:
                return True
            elif node is None or other is None or node.val != other.val:
                return False
            else:
                return helper(node.left, other.left) and helper(node.right, other.right)

        return helper(p, q)

        