# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        def helper(node, values):
            if node:
                values.append(helper(node.left, values + [node.val]))
                values.append(helper(node.right, values + [node.val]))
                return values
            else:
                return values
    
        return helper(p, list()) == helper(q, list())
            
            
