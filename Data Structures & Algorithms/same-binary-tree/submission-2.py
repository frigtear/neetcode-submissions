# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        def helper(node, other):
            if not node and not other:
                return True
            if not node or not other or other.val != node.val:
                return False
            return helper(node.left, other.left) and helper(node.right, other.right)
        
        return helper(p, q)
            
            
            
            
            
