# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


# upper bound = 5
# lower bound = float('-inf')
# 

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        
        def helper(node, p, q):

            if node:
                if max(p.val,q.val) < node.val:
                    return helper(node.left, p,q)
                elif min(p.val,q.val) > node.val:
                    return helper(node.right, p, q)
                else:
                    return node
            

        return helper(root, p, q)
            

                



