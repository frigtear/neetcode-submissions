# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def helper(node, maximum, minimum):
            
            if node:
                if not minimum < node.val < maximum:
                    return False
                else:
                    return helper(node.left, node.val, minimum) and helper(node.right, maximum, node.val)
            return True

        return helper(root, float('inf'), float('-inf'))



        