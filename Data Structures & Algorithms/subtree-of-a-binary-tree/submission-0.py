# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        
        def isEqual(node, other):
            if not node and not other:
                return True
            if not node or not other or node.val != other.val:
                return False
            return isEqual(node.left, other.left) and isEqual(node.right, other.right)
        
        def helper(root, subroot):

            if root and isEqual(root, subroot):
                return True
            elif root:
                return helper(root.left, subroot) or helper(root.right, subroot)
            else:
                return False

        return helper(root, subRoot)