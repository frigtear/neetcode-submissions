# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        result = 0
        def helper(node, max_value):
            nonlocal result
            if node:
                if node.val >= max_value:
                    result += 1
                
                max_value = max(max_value, node.val)
                helper(node.left, max_value) 
                helper(node.right, max_value)

        helper(root, root.val)
        return result
