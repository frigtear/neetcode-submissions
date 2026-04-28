# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
   
 
        result = 0 

        def helper(root): 
            nonlocal result     
          
            if root:
                left = helper(root.left)
                right = helper(root.right)
                result = max(result, left + right)
                return 1 + max(left, right)
            else:
                return 0

        helper(root)
        return result

        



    
        