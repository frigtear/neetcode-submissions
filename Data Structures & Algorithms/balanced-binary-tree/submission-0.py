# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        isBalanced = True 

        def helper(node):
            nonlocal isBalanced
            if node:

                left = 1 + helper(node.left)
                right = 1 + helper(node.right)
                if abs(left - right) > 1:
                    isBalanced = False
                return max(left, right)

            else:
                return 0

        helper(root)
        return isBalanced


                